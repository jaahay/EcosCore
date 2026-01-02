// File: include/ecoscore/meta/CycleCheck.h
#ifndef ECOSCORE_META_CYCLECHECK_H_
#define ECOSCORE_META_CYCLECHECK_H_

/**
 * @file CycleCheck.h
 * @brief Compile-time utilities to detect cycles in type dependency graphs.
 *
 * @details
 * This header provides the template `CheckNoCycle` that recursively inspects
 * a type's dependency list to ensure no cyclic references exist, preventing
 * infinite recursion or logical errors in type priority orderings.
 */

#include "ecoscore/meta/TypeList.h"
#include <type_traits>

namespace ecoscore::meta {

    /**
     * @brief Compile-time check to detect cycles in a type dependency graph.
     *
     * @tparam T The type to check.
     * @tparam Visited A TypeList of previously visited types to detect cycles.
     *
     * @note The type T is expected to have a nested alias `HigherThanList` of type `TypeList<>`
     *       representing its dependencies.
     */
    template <typename T, typename Visited = TypeList<>>
    struct CheckNoCycle {
        static_assert(!Contains<T, Visited>::value, "Cycle detected in priority ordering!");

    private:
        using NewVisited = Append_t<Visited, T>;

        template <typename List>
        struct Impl;

        template <>
        struct Impl<TypeList<>> {
            static constexpr bool value = true;
        };

        template <typename Head, typename... Tail>
        struct Impl<TypeList<Head, Tail...>> {
            static constexpr bool value =
                CheckNoCycle<Head, NewVisited>::value&& Impl<TypeList<Tail...>>::value;
        };

    public:
        static constexpr bool value = Impl<typename T::HigherThanList>::value;
    };

} // namespace ecoscore::meta

#endif // ECOSCORE_META_CYCLECHECK_H_
