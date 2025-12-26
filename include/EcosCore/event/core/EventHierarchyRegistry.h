// EcosCore/event/core/EventHierarchyRegistry.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H

#include <typeindex>
#include <vector>
#include <unordered_map>
#include <mutex>

namespace ecoscore::event::core {

    class EventHierarchyRegistry {
    public:
        static EventHierarchyRegistry& instance() {
            static EventHierarchyRegistry inst;
            return inst;
        }

        // Register base types for a derived event type
        void RegisterHierarchy(std::type_index derived, std::vector<std::type_index> bases) {
            std::lock_guard lock(mutex_);
            registry_[derived] = std::move(bases);
        }

        // Retrieve hierarchy: base types first, then derived
        std::vector<std::type_index> GetHierarchy(std::type_index type) const {
            std::lock_guard lock(mutex_);
            auto it = registry_.find(type);
            if (it != registry_.end()) {
                // Copy bases + derived type
                auto vec = it->second;
                vec.push_back(type);
                return vec;
            }
            // Default: only the type itself
            return { type };
        }

    private:
        mutable std::mutex mutex_;
        std::unordered_map<std::type_index, std::vector<std::type_index>> registry_;
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H
