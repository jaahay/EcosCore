// File: ecoscore/event/helpers/EventHierarchyHelpers.h
// EcosCore/event/EventHierarchyHelpers.h
#ifndef ECOSCORE_EVENT_HELPERS_EVENTHIERARCHYHELPERS_H
#define ECOSCORE_EVENT_HELPERS_EVENTHIERARCHYHELPERS_H

#include <type_traits>
#include <typeindex>
#include <algorithm>
#include "EcosCore/event/EventHierarchy.h"

namespace EcosCore::event {

    /**
     * Helper to check if BaseEvent is a base of DerivedEvent in the given hierarchy.
     */
    template <typename BaseEvent, typename DerivedEvent>
    bool IsBaseEventOf(const EventHierarchy& hierarchy) {
        static_assert(std::is_base_of_v<BaseEvent, DerivedEvent>, "DerivedEvent must inherit BaseEvent");

        std::type_index derivedType = typeid(DerivedEvent);
        std::type_index baseType = typeid(BaseEvent);

        const auto& bases = hierarchy.GetBaseEvents(derivedType);
        return std::find(bases.begin(), bases.end(), baseType) != bases.end();
} // namespace EcosCore::event

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_HELPERS_EVENTHIERARCHYHELPERS_H
