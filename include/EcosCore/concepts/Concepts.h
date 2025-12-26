// EcosCore/concepts/Concepts.h
#ifndef ECOSCORE_CONCEPTS_CONCEPTS_H
#define ECOSCORE_CONCEPTS_CONCEPTS_H

#include <type_traits>
#include <concepts>
#include "EcosCore/state/BaseState.h"
#include "EcosCore/event/Event.h"

namespace ecoscore::concepts {

    // State concepts
    template <typename T>
    concept DerivedFromBaseState = std::is_base_of_v<ecoscore::state::BaseState, T>;

    template <typename T>
    concept SingletonState = requires {
        { T::instance() } -> std::same_as<const T&>;
    };

    template <typename T>
    concept ConcreteState = DerivedFromBaseState<T> && !std::is_abstract_v<T>;

    // Event concepts
    template <typename T>
    concept EventType = std::is_base_of_v<ecoscore::event::Event, T>;

    template <typename F, typename EventT>
    concept CallableWithEvent = requires(F f, EventT e) {
        { f(e) } -> std::same_as<void>;
    };

} // namespace ecoscore::concepts

#endif // ECOSCORE_CONCEPTS_CONCEPTS_H
