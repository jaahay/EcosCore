// EcosCore/event/core/BaseEventList.h
#ifndef ECOSCORE_EVENT_CORE_BASE_EVENT_LIST_H
#define ECOSCORE_EVENT_CORE_BASE_EVENT_LIST_H

#include <tuple>

namespace EcosCore::event::core {

    /**
     * BaseEventList: compile-time list of event types.
     * Used for compile-time event hierarchy definitions.
     */
    template <typename... Events>
    struct BaseEventList {
        using type = std::tuple<Events...>;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_EVENT_CORE_BASE_EVENT_LIST_H
