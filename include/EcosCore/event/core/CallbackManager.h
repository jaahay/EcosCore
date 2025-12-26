// EcosCore/event/core/CallbackManager.h
#ifndef ECOSCORE_EVENT_CALLBACK_MANAGER_H
#define ECOSCORE_EVENT_CALLBACK_MANAGER_H

#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/Types.h"
#include "EcosCore/state/PriorityState.h"

#include <unordered_map>
#include <vector>
#include <typeindex>
#include <mutex>
#include <memory>
#include <algorithm>

using namespace ecoscore::state;

namespace ecoscore::event::core {

    class CallbackManager {
    public:
        CallbackManager() = default;

        template <typename EventT, typename F>
        CallbackHandle AddCallback(F&& cb,
            const CallbackPhaseState& phase,
            const PriorityState& priority) {
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

        std::vector<std::pair<CallbackHandle, std::unique_ptr<IEventCallback>>> GetCallbacks(std::type_index type) const {
            std::lock_guard lock(mutex_);
            auto found = callbacks_.find(type);
            if (found != callbacks_.end())
                return found->second;
            return {};
        }

    private:
        void SortCallbacksByPriority(std::vector<std::pair<CallbackHandle, std::unique_ptr<IEventCallback>>>& vec) {
            std::stable_sort(vec.begin(), vec.end(),
                [](const auto& a, const auto& b) {
                    auto p1 = dynamic_cast<const PriorityState*>(a.second->Priority());
                    auto p2 = dynamic_cast<const PriorityState*>(b.second->Priority());
                    if (!p1 || !p2) return false;
                    return (*p1) < (*p2);
                });
        }

        mutable std::mutex mutex_;
        std::unordered_map<std::type_index, std::vector<std::pair<CallbackHandle, std::unique_ptr<IEventCallback>>>> callbacks_;
        CallbackHandle nextHandle_ = 1;
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_CALLBACK_MANAGER_H
