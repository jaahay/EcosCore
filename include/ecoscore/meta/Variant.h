// File: ecoscore/meta/Variant.h
#ifndef ECOSCORE_META_VARIANT_H_
#define ECOSCORE_META_VARIANT_H_

/**
 * @file Variant.h
 * @brief Compile-time utilities to convert tuples to variants and concatenate variants.
 *
 * @details
 * Provides templates to convert a std::tuple of types into a std::variant of those types,
 * and to concatenate multiple std::variant types into a single variant type.
 */

#include "ecoscore/meta/Tuple.h"
#include <tuple>
#include <variant>

namespace ecoscore::meta {

    /**
     * @brief Converts a std::tuple of types into a std::variant of those types.
     *
     * @tparam Tuple The std::tuple type to convert.
     */
    template <typename Tuple>
    struct tuple_to_variant;

    template <typename... Ts>
    struct tuple_to_variant<std::tuple<Ts...>> {
        using type = std::variant<Ts...>;
    };

    /**
     * @brief Alias template for tuple_to_variant.
     */
    template <typename Tuple>
    using tuple_to_variant_t = typename tuple_to_variant<Tuple>::type;

    /**
     * @brief Concatenates multiple std::variant types into a single variant type.
     *
     * @tparam Variants Variadic list of std::variant types.
     *
     * @note This implementation converts each variant into a tuple of types,
     *       concatenates those tuples, then converts back to a variant.
     */
    template <typename... Variants>
    struct variant_concat {
    private:
        using concatenated_tuple = tuple_concat_many_t<typename tuple_to_variant<Variants>::type...>;
    public:
        using type = tuple_to_variant_t<concatenated_tuple>;
    };

    /**
     * @brief Alias template for variant_concat.
     */
    template <typename... Variants>
    using variant_concat_t = typename variant_concat<Variants...>::type;

} // namespace ecoscore::meta

#endif // ECOSCORE_META_VARIANT_H_
