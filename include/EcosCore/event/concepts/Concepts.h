// File: ecoscore/event/concepts/Concepts.h
// EcosCore/event/concepts/Concepts.h
#ifndef ECOSCORE_ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H
#define ECOSCORE_ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H

#include <concepts>
#include "EcosCore/event/Event.h"
#include "EcosCore/tag/concepts/Concepts.h"

namespace EcosCore::event::concepts {

    /**
     * Concept for event types derived from EcosCore::event::Event.
     */
    template <typename T>
    concept EventType = std::is_base_of_v<EcosCore::event::Event, T>;

    /**
     * Concept for callable objects accepting an event type.
     */
    template <typename F, typename EventT>
    concept CallableWithEvent = requires(F f, EventT e) {
        { f(e) } -> std::same_as<void>;
    };

    /**
     * Concept for Phase tags.
     */
    template <typename T>
    concept PhaseTag = EcosCore::tag::concepts::PhaseTag<T>;

    /**
     * Concept for Priority tags.
     */
    template <typename T>
    concept PriorityTag = EcosCore::tag::concepts::PriorityTag<T>;

} // namespace EcosCore::event::concepts

#endif // ECOSCORE_ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H
