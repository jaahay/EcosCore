// EcosCore/event/EventHierarchy.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_H

#include <typeindex>
#include <vector>

namespace ecoscore::event {

    // Default: event hierarchy is just the event itself
    template <typename EventT>
    struct EventHierarchy {
        static const std::vector<std::type_index>& Get() {
            static const std::vector<std::type_index> hierarchy = { std::type_index(typeid(EventT)) };
            return hierarchy;
        }
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_H
