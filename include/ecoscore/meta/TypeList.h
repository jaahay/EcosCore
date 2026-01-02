// File: include/ecoscore/meta/TypeList.h
#ifndef ECOSCORE_META_TYPELIST_H_
#define ECOSCORE_META_TYPELIST_H_

/**
 * @file TypeList.h
 * @brief Compile-time immutable list of types and associated utilities.
 *
 * @details
 * Provides a variadic template `TypeList` to represent a list of types at compile time,
 * along with metafunctions for appending, checking containment, and removing types.
 */

#include <type_traits>

namespace ecoscore::meta {

    /**
     * @brief A compile-time immutable list of types.
     *
     * @tparam Ts Types contained in the list.
     */
    template <typename... Ts>
    struct TypeList {
        /// Tag to identify TypeList conceptually.
        using is_type_list_tag = void;

        /// Number of types in the list.
        static constexpr size_t size = sizeof...(Ts);

        /// Whether the list is empty.
        static constexpr bool empty = (size == 0);
    };

    /**
     * @brief Append a type T to a TypeList.
     *
     * @tparam List The original TypeList.
     * @tparam T The type to append.
     */
    template <typename List, typename T>
    struct Append;

    template <typename... Ts, typename T>
    struct Append<TypeList<Ts...>, T> {
        using type = TypeList<Ts..., T>;
    };

    /**
     * @brief Alias for Append result type.
     */
    template <typename List, typename T>
    using Append_t = typename Append<List, T>::type;

    /**
     * @brief Check if a TypeList contains a type T.
     *
     * @tparam List The TypeList to check.
     * @tparam T The type to find.
     */
    template <typename List, typename T>
    struct Contains : std::false_type {};

    template <typename T, typename... Ts>
    struct Contains<TypeList<T, Ts...>, T> : std::true_type {};

    template <typename T, typename U, typename... Ts>
    struct Contains<TypeList<U, Ts...>, T> : Contains<TypeList<Ts...>, T> {};

    /**
     * @brief Boolean variable template for Contains.
     */
    template <typename List, typename T>
    inline constexpr bool Contains_v = Contains<List, T>::value;

    /**
     * @brief Remove a type T from a TypeList.
     *
     * @tparam List The original TypeList.
     * @tparam T The type to remove.
     */
    template <typename List, typename T>
    struct Remove;

    template <typename T>
    struct Remove<TypeList<>, T> {
        using type = TypeList<>;
    };

    template <typename T, typename... Ts>
    struct Remove<TypeList<T, Ts...>, T> {
        using type = TypeList<Ts...>;
    };

    template <typename U, typename T, typename... Ts>
    struct Remove<TypeList<U, Ts...>, T> {
    private:
        using TailResult = typename Remove<TypeList<Ts...>, T>::type;
    public:
        using type = Append_t<TypeList<U>, TailResult>;
    };

    /**
     * @brief Alias for Remove result type.
     */
    template <typename List, typename T>
    using Remove_t = typename Remove<List, T>::type;

} // namespace ecoscore::meta

#endif // ECOSCORE_META_TYPELIST_H_
