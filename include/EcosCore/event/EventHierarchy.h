// File: ecoscore/event/EventHierarchy.h
// EcosCore/event/EventHierarchy.h
#ifndef ECOSCORE_EVENT_EVENTHIERARCHY_H
#define ECOSCORE_EVENT_EVENTHIERARCHY_H

#include <vector>
#include <typeindex>
#include <unordered_map>

namespace EcosCore::event {

    /**
     * EventHierarchy: manages base and derived event type relationships.
     */
    class EventHierarchy {
    public:
        EventHierarchy() = default;

        void AddBaseEvent(std::type_index derived, std::type_index base) {
            base_map_[derived].push_back(base);
            derived_map_[base].push_back(derived);
} // namespace EcosCore::event

        const std::vector<std::type_index>& GetBaseEvents(std::type_index derived) const {
            static const std::vector<std::type_index> empty;
            auto it = base_map_.find(derived);
            return it != base_map_.end() ? it->second : empty;
        }

        const std::vector<std::type_index>& GetDerivedEvents(std::type_index base) const {
            static const std::vector<std::type_index> empty;
            auto it = derived_map_.find(base);
            return it != derived_map_.end() ? it->second : empty;
        }

    private:
        std::unordered_map<std::type_index, std::vector<std::type_index>> base_map_;
        std::unordered_map<std::type_index, std::vector<std::type_index>> derived_map_;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_EVENTHIERARCHY_H
