// EcosCore/event/core/EventDispatcher.h
#ifndef ECOSCORE_EVENT_EVENT_DISPATCHER_H
#define ECOSCORE_EVENT_EVENT_DISPATCHER_H

#include "EcosCore/event/core/CallbackPhaseState.h"
#include "EcosCore/event/core/CallbackPriorityState.h"
#include "EcosCore/event/core/Event.h"
#include "EcosCore/event/core/EventHierarchy.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/state/BaseState.h"
#include "CallbackManager.h"
#include "PhaseInvoker.h"

#include <functional>
#include <mutex>
#include <typeindex>
#include <vector>

namespace ecoscore::event::core {

    using FallbackCallback = std::function<void(const Event&, const EventContext&)>;

    class EventDispatcher {
    public:
        EventDispatcher() = default;
        virtual ~EventDispatcher() = default;

        template <typename EventT, typename F>
        CallbackHandle AddCallback(F&& cb,
            const CallbackPhaseState& phase,
            const CallbackPriorityState& priority) {
            return callbackManager_.AddCallback<EventT>(std::forward<F>(cb), phase, priority);
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

            // Use compile-time cached hierarchy if possible
            // Otherwise fallback to runtime cache
            const auto& hierarchy = [&]() -> const std::vector<std::type_index>&{
                // Try to get compile-time hierarchy by dynamic cast
                // (if you know the actual type, use DispatchTyped instead)
                return EventHierarchyCache::Get(std::type_index(typeid(event)));
                }();

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

        // Optional: dispatch with known compile-time event type for max efficiency
        template <typename EventT>
        void DispatchTyped(const EventT& event) const {
            EventContext ctx;
            const auto& hierarchy = EventHierarchyCache::Get<EventT>();

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
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_EVENT_DISPATCHER_H
