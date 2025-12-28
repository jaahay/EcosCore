// include/ecoscore/EcosCoreFwd.h
#ifndef ECOSCORE_ECOSCOREFWD_H
#define ECOSCORE_ECOSCOREFWD_H

/**
 * @file EcosCoreFwd.h
 * @brief Forward declarations and minimal common concepts for EcosCore.
 *
 * This header provides lightweight declarations and concepts used internally
 * across EcosCore domains to reduce dependencies and improve compilation times.
 */

#include <concepts>
#include <string_view>
#include <type_traits>

namespace ecoscore {

    // Forward declarations for core domain types

    namespace meta {
        template <typename... Ts>
        struct TypeList;

        template <typename T, typename List>
        struct Contains;
    }

    namespace tag {
        template <typename Derived>
        struct Tag;
    }

    namespace type {
        struct StructType;

        template <typename Derived, typename Parent>
        struct TemplateType;
    }

    // Common concepts

    namespace concepts {

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

    } // namespace concepts

} // namespace ecoscore

#endif // ECOSCORE_ECOSCOREFWD_H
