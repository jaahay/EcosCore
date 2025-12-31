// EcosCore/event/EventHierarchyRegistry.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <mutex>
#include "EcosCore/event/EventHierarchy.h"

namespace EcosCore::event {

    /**
     * EventHierarchyRegistry:
     * Manages registration and lookup of event hierarchies keyed by base event type.
     */
    class EventHierarchyRegistry {
    public:
        static EventHierarchyRegistry& instance() {
            static EventHierarchyRegistry inst;
            return inst;
        }

        void RegisterHierarchy(std::type_index baseEvent, std::shared_ptr<EventHierarchy> hierarchy) {
            std::lock_guard lock(mutex_);
            hierarchies_[baseEvent] = hierarchy;
        }

        std::shared_ptr<EventHierarchy> GetHierarchy(std::type_index baseEvent) {
            std::lock_guard lock(mutex_);
            auto it = hierarchies_.find(baseEvent);
            if (it != hierarchies_.end()) {
                return it->second;
            }
            return nullptr;
        }

    private:
        EventHierarchyRegistry() = default;
        ~EventHierarchyRegistry() = default;
        EventHierarchyRegistry(const EventHierarchyRegistry&) = delete;
        EventHierarchyRegistry& operator=(const EventHierarchyRegistry&) = delete;

        std::mutex mutex_;
        std::unordered_map<std::type_index, std::shared_ptr<EventHierarchy>> hierarchies_;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_REGISTRY_H
