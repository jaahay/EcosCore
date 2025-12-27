// EcosCore/event/EventDispatcher.h
#ifndef ECOSCORE_EVENT_EVENT_DISPATCHER_H
#define ECOSCORE_EVENT_EVENT_DISPATCHER_H

#include "EcosCore/event/Types.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/PriorityState.h"
#include "EcosCore/event/Event.h"
#include "EcosCore/event/EventHierarchy.h"
#include "EcosCore/event/EventContext.h"
#include "CallbackManager.h"
#include "PhaseInvoker.h"

#include <functional>
#include <mutex>
#include <typeindex>
#include <vector>
#include <memory>

namespace ecoscore::event {

    using FallbackCallback = std::function<void(const Event&, const EventContext&)>;

    class EventDispatcher {
    public:
        EventDispatcher() = default;
        virtual ~EventDispatcher() = default;

        // Overload 1: AddCallback with callable
        template <typename EventT, typename F>
        CallbackHandle AddCallback(F&& cb,
            const CallbackPhaseState& phase,
            const PriorityState& priority) {
            return callbackManager_.AddCallback<EventT>(std::forward<F>(cb), phase, priority);
        }

        // Overload 2: AddCallback with IEventCallback singleton reference (no ownership)
        CallbackHandle AddCallback(const IEventCallback& callback,
            const CallbackPhaseState& phase,
            const PriorityState& priority) {
            std::lock_guard lock(mutex_);
            auto handle = CallbackHandle(nextHandle_++);
            // Wrap singleton pointer with no-op deleter
            auto cbPtr = std::unique_ptr<IEventCallback, std::function<void(IEventCallback*)>>(
                const_cast<IEventCallback*>(&callback),
                [](IEventCallback*) {}
            );
            auto& vec = callbackManager_.callbacks_[std::type_index(typeid(callback))];
            vec.emplace_back(handle, std::move(cbPtr));
            callbackManager_.SortCallbacksByPriority(vec);
            return handle;
        }

        bool RemoveCallback(CallbackHandle handle) {
            return callbackManager_.RemoveCallback(handle);
        }

        void SetFallbackCallback(FallbackCallback fallback) {
            std::lock_guard lock(mutex_);
            fallbackCallback_ = std::move(fallback);
        }

        void Dispatch(const Event& event) const {
            EventContext ctx;

            const auto& hierarchy = EventHierarchyCache::instance().Get(std::type_index(typeid(event)));

            PhaseInvoker invoker(callbackManager_);
            bool stopped = false;

            if (invoker.InvokePhase(hierarchy, event, BeforePhase::instance(), true, ctx))
                stopped = true;
            else if (invoker.InvokePhase(hierarchy, event, MainPhase::instance(), false, ctx))
                stopped = true;
            else if (invoker.InvokePhase(hierarchy, event, AfterPhase::instance(), false, ctx))
                stopped = true;

            if (stopped) {
                std::lock_guard lock(mutex_);
                if (fallbackCallback_)
                    fallbackCallback_(event, ctx);
            }
        }

    private:
        CallbackManager callbackManager_;
        mutable std::mutex mutex_;
        FallbackCallback fallbackCallback_;
        std::size_t nextHandle_ = 1;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_DISPATCHER_H
