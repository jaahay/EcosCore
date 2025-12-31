// /src/ecoscore/meta/Tuple.ixx
export module ecoscore.meta.Tuple;

import std;

namespace ecoscore::meta {

    /**
     * @brief Concatenates two std::tuple types into a single tuple type.
     *
     * @tparam Tuple1 First tuple type.
     * @tparam Tuple2 Second tuple type.
     */
    export template <typename Tuple1, typename Tuple2>
        struct tuple_concat;

    template <typename... Ts1, typename... Ts2>
    struct tuple_concat<std::tuple<Ts1...>, std::tuple<Ts2...>> {
        using type = std::tuple<Ts1..., Ts2...>;
    };

    /**
     * @brief Alias template for tuple_concat.
     */
    export template <typename Tuple1, typename Tuple2>
        using tuple_concat_t = typename tuple_concat<Tuple1, Tuple2>::type;

    /**
     * @brief Concatenates multiple std::tuple types into a single tuple type.
     *
     * @tparam Tuples Variadic list of tuple types.
     */
    export template <typename... Tuples>
        struct tuple_concat_many;

    template <>
    struct tuple_concat_many<> {
        using type = std::tuple<>;
    };

    template <typename T>
    struct tuple_concat_many<T> {
        static_assert(std::is_same_v<T, std::tuple<typename std::tuple_element<0, T>::type>>,
            "tuple_concat_many<T>: T must be a std::tuple");
        using type = T;
    };

    template <typename T1, typename T2, typename... Ts>
    struct tuple_concat_many<T1, T2, Ts...> {
        static_assert(std::is_same_v<T1, std::tuple<typename std::tuple_element<0, T1>::type>>,
            "tuple_concat_many<T1, T2, ...>: T1 must be a std::tuple");
        static_assert(std::is_same_v<T2, std::tuple<typename std::tuple_element<0, T2>::type>>,
            "tuple_concat_many<T1, T2, ...>: T2 must be a std::tuple");

        using type = typename tuple_concat_many<
            tuple_concat_t<T1, T2>,
            Ts...
        >::type;
    };

    /**
     * @brief Alias template for tuple_concat_many.
     */
    export template <typename... Tuples>
        using tuple_concat_many_t = typename tuple_concat_many<Tuples...>::type;

} // namespace ecoscore::meta
