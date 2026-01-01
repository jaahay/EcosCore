// File: ecoscore/callback/core/BaseEventList.h
// EcosCore/event/core/BaseEventList.h
#ifndef ECOSCORE_ECOSCORE_CALLBACK_CORE_BASEEVENTLIST_H
#define ECOSCORE_ECOSCORE_CALLBACK_CORE_BASEEVENTLIST_H

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

#endif // ECOSCORE_ECOSCORE_CALLBACK_CORE_BASEEVENTLIST_H
