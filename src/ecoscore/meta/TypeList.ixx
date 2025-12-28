// src/ecoscore/meta/TypeList.ixx
module ecoscore.meta.TypeList;

import <type_traits>;

export namespace ecoscore::meta {

    /**
     * @brief Compile-time list of types.
     * @tparam Ts Types contained in the list.
     */
    template <typename... Ts>
    struct TypeList {};

    /**
     * @brief Checks if a type T is contained within a TypeList.
     * @tparam T Type to check.
     * @tparam List TypeList to search.
     */
    template <typename T, typename List>
    struct Contains;

    template <typename T>
    struct Contains<T, TypeList<>> : std::false_type {};

    template <typename T, typename Head, typename... Tail>
    struct Contains<T, TypeList<Head, Tail...>> : std::conditional_t<
        std::is_same_v<T, Head>,
        std::true_type,
        Contains<T, TypeList<Tail...>>
    > {
    };

    /**
     * @brief Appends a type T to a TypeList.
     * @tparam List Input TypeList.
     * @tparam T Type to append.
     */
    template <typename List, typename T>
    struct Append;

    template <typename... Ts, typename T>
    struct Append<TypeList<Ts...>, T> {
        using type = TypeList<Ts..., T>;
    };

}
