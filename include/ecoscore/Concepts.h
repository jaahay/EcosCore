// include/ecoscore/Concepts.h
#ifndef ECOSCORE_CONCEPTS_H
#define ECOSCORE_CONCEPTS_H

#include <concepts>
#include <string_view>

namespace ecoscore::concepts {

    /**
     * @brief Concept for singleton types with static instance() and name().
     */
    template <typename T>
    concept SingletonTag = requires {
        { T::instance() } -> std::same_as<const T&>;
        { T::name() } -> std::convertible_to<std::string_view>;
    };

    /**
     * @brief Concept for CRTP tag categories.
     *
     * @tparam T The type to check.
     * @tparam Base The CRTP base template.
     */
    template <typename T, template <typename> typename Base>
    concept TagCategory = std::derived_from<T, Base<T>>;

} // namespace ecoscore::concepts

#endif // ECOSCORE_CONCEPTS_H
