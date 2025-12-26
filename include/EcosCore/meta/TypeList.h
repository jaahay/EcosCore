// EcosCore/meta/TypeList.h
#ifndef ECOSCORE_META_TYPELIST_H
#define ECOSCORE_META_TYPELIST_H

#include <type_traits>

namespace ecoscore::meta {

    template <typename... Ts>
    struct TypeList {};

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

    template <typename List, typename T>
    struct Append;

    template <typename... Ts, typename T>
    struct Append<TypeList<Ts...>, T> {
        using type = TypeList<Ts..., T>;
    };

} // namespace ecoscore::meta

#endif // ECOSCORE_META_TYPELIST_H
