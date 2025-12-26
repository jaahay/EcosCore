// EcosCore/event/helpers/EventHierarchyHelpers.h
#ifndef ECOSCORE_EVENT_HELPERS_EVENT_HIERARCHY_HELPERS_H
#define ECOSCORE_EVENT_HELPERS_EVENT_HIERARCHY_HELPERS_H

#define ECOSCORE_REGISTER_BASE_EVENTS(Derived, ...) \
    template <> \
    struct ecoscore::event::BaseEventList<Derived> { \
        using type = std::tuple<__VA_ARGS__>; \
    };

#endif // ECOSCORE_EVENT_HELPERS_EVENT_HIERARCHY_HELPERS_H
