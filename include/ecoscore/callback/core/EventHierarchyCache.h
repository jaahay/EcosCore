// EcosCore/event/EventHierarchyCache.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H

#include <mutex>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "EcosCore/event/EventHierarchy.h"

namespace EcosCore::event {

    /**
     * EventHierarchyCache:
     * Thread-safe singleton cache for event hierarchies keyed by base event type.
     * Supports multiple independent hierarchies distinguished by base event types.
     */
    class EventHierarchyCache {
    public:
        static EventHierarchyCache& instance() {
            static EventHierarchyCache inst;
            return inst;
        }

        std::shared_ptr<EventHierarchy> GetOrCreate(std::type_index baseEvent) {
            std::lock_guard lock(mutex_);
            auto it = cache_.find(baseEvent);
            if (it != cache_.end()) {
                return it->second;
            }
            auto hierarchy = std::make_shared<EventHierarchy>();
            cache_[baseEvent] = hierarchy;
            return hierarchy;
        }

    private:
        EventHierarchyCache() = default;
        ~EventHierarchyCache() = default;
        EventHierarchyCache(const EventHierarchyCache&) = delete;
        EventHierarchyCache& operator=(const EventHierarchyCache&) = delete;

        std::mutex mutex_;
        std::unordered_map<std::type_index, std::shared_ptr<EventHierarchy>> cache_;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H
