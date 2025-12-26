// EcosCore/meta/CycleCheck.h
#ifndef ECOSCORE_META_CYCLE_CHECK_H
#define ECOSCORE_META_CYCLE_CHECK_H

#include "TypeList.h"

namespace ecoscore::meta {

    template <typename T, typename Visited = TypeList<>>
    struct CheckNoCycle;

    template <typename T, typename Visited>
    struct CheckNoCycle {
        static_assert(!Contains<T, Visited>::value, "Cycle detected in priority ordering!");

        using NewVisited = typename Append<Visited, T>::type;

        template <typename List>
        struct CheckList;

        template <>
        struct CheckList<TypeList<>> {
            static constexpr bool value = true;
        };

        template <typename Head, typename... Tail>
        struct CheckList<TypeList<Head, Tail...>> {
            static constexpr bool value =
                CheckNoCycle<Head, NewVisited>::value&& CheckList<TypeList<Tail...>>::value;
        };

        static constexpr bool value = CheckList<typename T::HigherThanList>::value;
    };

} // namespace ecoscore::meta

#endif // ECOSCORE_META_CYCLE_CHECK_H
