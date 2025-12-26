// EcosCore/event/EventDispatcher.h
#ifndef ECOSCORE_EVENT_EVENT_DISPATCHER_H
#define ECOSCORE_EVENT_EVENT_DISPATCHER_H

#include "EcosCore/concepts/Concepts.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/Event.h"
#include "Ecoscore/event/EventCallback.h"
#include "Ecoscore/event/EventHierarchy.h"
#include "Ecoscore/state/BaseState.h"

#include <unordered_map>
#include <vector>
#include <typeindex>
#include <mutex>
#include <memory>
#include <algorithm>
#include <iostream>

namespace ecoscore::event {

    using CallbackHandle = size_t;

    class EventDispatcher {
    public:
        EventDispatcher() : nextHandle_(1) {}

        template <ecoscore::concepts::EventType EventT, typename F>
            requires ecoscore::concepts::CallableWithEvent<F, EventT>
        CallbackHandle AddCallback(F&& cb,
            const ecoscore::state::BaseState& phase,
            const ecoscore::state::BaseState& priority) {
            auto handle = nextHandle_++;
            auto callback = std::make_unique<EventCallback<EventT>>(std::forward<F>(cb), phase, priority);

            std::lock_guard lock(mutex_);
            auto& vec = callbacks_[std::type_index(typeid(EventT))];
            vec.emplace_back(handle, std::move(callback));
            SortCallbacksByPriority(vec);
            return handle;
        }

        bool RemoveCallback(CallbackHandle handle) {
            std::lock_guard lock(mutex_);
            for (auto& [type, vec] : callbacks_) {
                auto it = std::remove_if(vec.begin(), vec.end(),
                    [handle](const auto& pair) { return pair.first == handle; });
                if (it != vec.end()) {
                    vec.erase(it, vec.end());
                    return true;
                }
            }
            return false;
        }

        void Dispatch(const Event& event) const {
            auto hierarchy = GetEventHierarchy(typeid(event));

            if (InvokePhaseCallbacks(hierarchy, event, *ecoscore::event::BeforePhase::instance(), true))
                return;

            if (InvokePhaseCallbacks(hierarchy, event, *ecoscore::event::MainPhase::instance(), false))
                return;

            InvokePhaseCallbacks(hierarchy, event, *ecoscore::event::AfterPhase::instance(), false);
        }

    private:
        std::unordered_map<std::type_index, std::vector<std::pair<CallbackHandle, std::unique_ptr<IEventCallback>>>> callbacks_;
        mutable std::mutex mutex_;
        CallbackHandle nextHandle_;

        static void SortCallbacksByPriority(std::vector<std::pair<CallbackHandle, std::unique_ptr<IEventCallback>>>& vec) {
            std::stable_sort(vec.begin(), vec.end(),
                [](const auto& a, const auto& b) {
                    const auto* p1 = a.second->Priority();
                    const auto* p2 = b.second->Priority();
                    if (!p1 || !p2) return false;
                    return (*p1) < (*p2);
                });
        }

        bool InvokePhaseCallbacks(const std::vector<std::type_index>& hierarchy,
            const Event& event,
            const ecoscore::state::BaseState& phase,
            bool generalToSpecific) const {
            std::lock_guard lock(mutex_);

            if (generalToSpecific) {
                for (const auto& type : hierarchy) {
                    if (InvokeCallbacksForType(type, event, phase))
                        return true;
                }
            }
            else {
                for (auto it = hierarchy.rbegin(); it != hierarchy.rend(); ++it) {
                    if (InvokeCallbacksForType(*it, event, phase))
                        return true;
                }
            }
            return false;
        }

        bool InvokeCallbacksForType(std::type_index type,
            const Event& event,
            const ecoscore::state::BaseState& phase) const {
            auto found = callbacks_.find(type);
            if (found == callbacks_.end()) return false;

            for (const auto& [handle, cb] : found->second) {
                if (*(cb->Phase()) == phase) {
                    try {
                        if (cb->Invoke(event)) {
                            return true;
                        }
                    }
                    catch (const std::exception& ex) {
                        std::cerr << "Exception in event callback: " << ex.what() << "\n";
                    }
                    catch (...) {
                        std::cerr << "Unknown exception in event callback\n";
                    }
                }
            }
            return false;
        }

        std::vector<std::type_index> GetEventHierarchy(std::type_index eventType) const {
            return { eventType };
        }
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_DISPATCHER_H
