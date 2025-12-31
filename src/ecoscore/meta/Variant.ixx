// /src/ecoscore/meta/Variant.ixx
export module ecoscore.meta.Variant;

import <variant>;
import <tuple>;

import ecoscore.meta.Tuple;

namespace ecoscore::meta {

    /**
     * @brief Converts a std::tuple of types into a std::variant of those types.
     *
     * @tparam Tuple The std::tuple type to convert.
     */
    export template <typename Tuple>
        struct tuple_to_variant;

    template <typename... Ts>
    struct tuple_to_variant<std::tuple<Ts...>> {
        using type = std::variant<Ts...>;
    };

    /**
     * @brief Alias template for tuple_to_variant.
     */
    export template <typename Tuple>
        using tuple_to_variant_t = typename tuple_to_variant<Tuple>::type;

    /**
     * @brief Concatenates multiple std::variant types into a single variant type.
     *
     * @tparam Variants Variadic list of std::variant types.
     */
    export template <typename... Variants>
        struct variant_concat {
        private:
            using concatenated_tuple = tuple_concat_many_t<typename tuple_to_variant<Variants>::type...>;
        public:
            using type = tuple_to_variant_t<concatenated_tuple>;
    };

    /**
     * @brief Alias template for variant_concat.
     */
    export template <typename... Variants>
        using variant_concat_t = typename variant_concat<Variants...>::type;

} // namespace ecoscore::meta
