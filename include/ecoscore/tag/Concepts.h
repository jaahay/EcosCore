// include/ecoscore/tag/Concepts.h
#ifndef ECOSCORE_TAG_CONCEPTS_H
#define ECOSCORE_TAG_CONCEPTS_H

#include <type_traits>
#include <string_view>
#include <concepts>

namespace ecoscore::tag::concepts {

    /**
     * @brief Concept representing any valid tag type.
     */
    template <typename T>
    concept Tag = requires {
        typename T::DerivedType;
        requires std::is_final_v<T>;
        requires std::is_default_constructible_v<T> == false;
        { T::static_name() } -> std::convertible_to<std::string_view>;
        { T::instance() } -> std::same_as<const T&>;
    };

    /**
     * @brief Concept representing a tag belonging to a specific category CRTP base.
     *
     * @tparam T The tag type to check.
     * @tparam Category The CRTP base template (e.g., Flow, Outcome).
     */
    template <typename T, template<typename> typename Category>
    concept Category = Tag<T> && std::derived_from<T, Category<T>>;

    /**
     * @brief Concept for concrete (non-abstract) tags.
     */
    template <typename T>
    concept ConcreteCategory = Tag<T> && (!std::is_abstract_v<T>);

    /**
     * @brief Convenience concept for tags in the Flow category.
     */
    template <typename T>
    concept FlowCategory = Category<T, ecoscore::tag::Flow>;

    /**
     * @brief Convenience concept for tags in the Outcome category.
     */
    template <typename T>
    concept OutcomeCategory = Category<T, ecoscore::tag::Outcome>;

    /**
     * @brief Convenience concept for tags in the Phase category.
     */
    template <typename T>
    concept PhaseCategory = Category<T, ecoscore::tag::Phase>;

}  // namespace ecoscore::tag::concepts

#endif  // ECOSCORE_TAG_CONCEPTS_H
