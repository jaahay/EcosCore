// src/ecoscore/type/Concepts.ixx
module ecoscore.type.Concepts;

import <type_traits>;
import <concepts>;
import ecoscore.type.StructType;
import ecoscore.tag.Tag;

export namespace ecoscore::type::concepts {

    /**
     * @brief Concept requiring T to be derived from StructType.
     */
    template <typename T>
    concept DerivedFromStructType = std::is_base_of_v<ecoscore::type::StructType, T>;

    /**
     * @brief Concept requiring T to be a concrete (non-abstract) StructType.
     */
    template <typename T>
    concept ConcreteType = DerivedFromStructType<T> && !std::is_abstract_v<T>;

    /**
     * @brief Concept for singleton tag types requiring instance() and name().
     */
    template <typename T>
    concept SingletonTag = requires {
        { T::instance() } -> std::same_as<const T&>;
        { T::name() } -> std::convertible_to<const char*>;
    }&& requires {
        { T::name() } noexcept;
    };

    /**
     * @brief Concept for tag categories derived from ecoscore::tag::Tag.
     */
    template <typename T>
    concept TagCategory = std::derived_from<T, ecoscore::tag::Tag<T>>;

}
