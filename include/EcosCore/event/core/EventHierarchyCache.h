// EcosCore/event/EventHierarchyCache.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H

#include <vector>
#include <typeindex>
#include <unordered_map>
#include <mutex>

namespace ecoscore::event {

    class EventHierarchyCache {
    public:
        static EventHierarchyCache& instance() {
            static EventHierarchyCache inst;
            return inst;
        }

        const std::vector<std::type_index>& Get(std::type_index type) {
            std::lock_guard lock(mutex_);
            auto it = cache_.find(type);
            if (it != cache_.end()) {
                return it->second;
            }
            static const std::vector<std::type_index> defaultVec{ type };
            return defaultVec;
        }

        void Insert(std::type_index type, std::vector<std::type_index> hierarchy) {
            std::lock_guard lock(mutex_);
            cache_[type] = std::move(hierarchy);
        }

    private:
        std::unordered_map<std::type_index, std::vector<std::type_index>> cache_;
        std::mutex mutex_;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_CACHE_H
