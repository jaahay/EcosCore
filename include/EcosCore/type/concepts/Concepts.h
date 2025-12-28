// EcosCore/type/concepts/Concepts.h
#ifndef ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
#define ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H

#include <type_traits>
#include <concepts>
#include "EcosCore/type/StructType.h"
#include "EcosCore/tag/Tag.h"

namespace EcosCore::type::concepts {

    /**
     * Concept for types derived from StructType.
     */
    template <typename T>
    concept DerivedFromStructType = std::is_base_of_v<EcosCore::type::StructType, T>;

    /**
     * Concept for concrete (non-abstract) types derived from StructType.
     */
    template <typename T>
    concept ConcreteType = DerivedFromStructType<T> && !std::is_abstract_v<T>;

    /**
     * Concept for singleton tag types.
     */
    template <typename T>
    concept SingletonTag = requires {
        { T::instance() } -> std::same_as<const T&>;
        { T::name() } -> std::convertible_to<const char*>;
    };

    /**
     * Concept for tag categories.
     */
    template <typename T>
    concept TagCategory = std::derived_from<T, EcosCore::tag::Tag<T>>;

} // namespace EcosCore::type::concepts

#endif // ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
