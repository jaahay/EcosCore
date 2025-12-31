// EcosCore/event/core/CallbackManager.h
#ifndef ECOSCORE_EVENT_CORE_CALLBACK_MANAGER_H
#define ECOSCORE_EVENT_CORE_CALLBACK_MANAGER_H

#include <vector>
#include <mutex>
#include <algorithm>
#include <iostream>
#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/IEventCallback.h"
#include "EcosCore/event/core/CallbackHandle.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/tag/PriorityOrderingGraph.h"  // updated include path

namespace EcosCore::event::core {

    /**
     * CallbackManager: manages callbacks for a single EventType, PhaseTag, PriorityTag.
     * Uses PriorityOrderingGraph for sorting callbacks by priority.
     */
    template <
        typename EventType,
        typename PhaseTag,
        typename PriorityTag
    >
    class CallbackManager : public IEventCallback {
    public:
        using CallbackType = EventCallback<EventType, PhaseTag, PriorityTag>;

        CallbackManager() = default;

        CallbackHandle RegisterCallback(const CallbackType& callback) {
            std::lock_guard lock(mutex_);
            auto handle = CallbackHandleGenerator::Generate();
            callbacks_.emplace_back(handle, callback);
            SortCallbacks();
            return handle;
        }

        void RemoveCallback(CallbackHandle handle) override {
            std::lock_guard lock(mutex_);
            callbacks_.erase(std::remove_if(callbacks_.begin(), callbacks_.end(),
                [handle](const auto& pair) { return pair.first == handle; }), callbacks_.end());
        }

        void Dispatch(const EventType& event, EventContext& ctx) override {
            for (const auto& [handle, cb] : callbacks_) {
                if (cb.phase() == PhaseTag::instance()) {
                    cb(event);
                    if (ctx.IsCanceled()) break;
                }
            }
        }

    private:
        void SortCallbacks() {
            std::sort(callbacks_.begin(), callbacks_.end(),
                [this](const auto& a, const auto& b) {
                    const auto& p1 = a.second.priority();
                    const auto& p2 = b.second.priority();

                    if (priorityOrderingGraph_.IsHigher(&p1, &p2)) return true;
                    if (priorityOrderingGraph_.IsHigher(&p2, &p1)) return false;

                    // Fallback deterministic ordering by name
                    return std::string(p1.names().name) < std::string(p2.names().name);
                });
        }

        std::vector<std::pair<CallbackHandle, CallbackType>> callbacks_;
        std::mutex mutex_;

        EcosCore::tag::PriorityOrderingGraph priorityOrderingGraph_;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_EVENT_CORE_CALLBACK_MANAGER_H
