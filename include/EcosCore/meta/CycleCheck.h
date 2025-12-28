// include/ecoscore/meta/CycleCheck.h
#ifndef ECOSCORE_META_CYCLE_CHECK_H
#define ECOSCORE_META_CYCLE_CHECK_H

#include "TypeList.h"

namespace ecoscore::meta {

    /**
     * @brief Compile-time check to detect cycles in a type dependency graph.
     * @tparam T Type to check.
     * @tparam Visited List of visited types to detect cycles.
     */
    template <typename T, typename Visited = TypeList<>>
    struct CheckNoCycle;

    template <typename T, typename Visited>
    struct CheckNoCycle {
        static_assert(!Contains<T, Visited>::value, "Cycle detected in priority ordering!");

        using NewVisited = typename Append<Visited, T>::type;

        template <typename List>
        struct _CheckList;

        template <>
        struct _CheckList<TypeList<>> {
            static constexpr bool value = true;
        };

        template <typename Head, typename... Tail>
        struct _CheckList<TypeList<Head, Tail...>> {
            static constexpr bool value =
                CheckNoCycle<Head, NewVisited>::value&& _CheckList<TypeList<Tail...>>::value;
        };

        static constexpr bool value = _CheckList<typename T::HigherThanList>::value;
    };

} // namespace ecoscore::meta

#endif // ECOSCORE_META_CYCLE_CHECK_H
