// EcosCore/event/concepts/Concepts.h
#ifndef ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H
#define ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H

#include "EcosCore/concepts/Concepts.h"

namespace ecoscore::event::concepts {

    using namespace ecoscore::concepts;

    template <typename F, typename EventT>
    concept CallableWithEventContext = requires(F f, const EventT & e, ecoscore::event::EventContext & ctx) {
        { f(e, ctx) };
    };

    template <typename T>
    concept EventCallbackType = std::is_base_of_v<IEventCallback, T>;

    template <typename T>
    concept PhaseState = DerivedFromBaseState<T>;

    template <typename T>
    concept PriorityState = DerivedFromBaseState<T>;

    template <typename T>
    concept ValidEventType = EventType<T>;

} // namespace ecoscore::event::concepts

#endif // ECOSCORE_EVENT_CONCEPTS_CONCEPTS_H
