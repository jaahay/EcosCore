// examples/EventHierarchySpecializations.cpp

#include "EcosCore/event/core/EventHierarchy.h"
#include <typeindex>
#include <vector>

// Your event types
struct BaseEvent : ecoscore::event::core::Event {};
struct DerivedEvent : BaseEvent {};

// Specialize EventHierarchy for DerivedEvent
template <>
struct ecoscore::event::core::EventHierarchy<DerivedEvent> {
    static const std::vector<std::type_index>& Get() {
        static const std::vector<std::type_index> hierarchy = {
            std::type_index(typeid(BaseEvent)),
            std::type_index(typeid(DerivedEvent))
        };
        return hierarchy;
    }
};
