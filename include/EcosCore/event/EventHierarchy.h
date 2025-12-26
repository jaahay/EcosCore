// EcosCore/event/EventHierarchy.h
#ifndef ECOSCORE_EVENT_EVENT_HIERARCHY_H
#define ECOSCORE_EVENT_EVENT_HIERARCHY_H

#include <tuple>
#include <typeindex>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <type_traits>

namespace ecoscore::event {

    template <typename EventT>
    struct BaseEventList {
        using type = std::tuple<>;
    };

    template <typename T, typename Tuple>
    struct Prepend;

    template <typename T, typename... Ts>
    struct Prepend<T, std::tuple<Ts...>> {
        using type = std::tuple<T, Ts...>;
    };

    template <typename T, typename Tuple>
    using Prepend_t = typename Prepend<T, Tuple>::type;

    template <typename EventT, typename BasesTuple = typename BaseEventList<EventT>::type>
    struct FullEventHierarchyHelper;

    template <typename EventT>
    struct FullEventHierarchyHelper<EventT, std::tuple<>> {
        using type = std::tuple<EventT>;
    };

    template <typename EventT, typename BaseHead, typename... BaseTail>
    struct FullEventHierarchyHelper<EventT, std::tuple<BaseHead, BaseTail...>> {
    private:
        using HeadHierarchy = typename FullEventHierarchyHelper<BaseHead>::type;
        using TailHierarchy = typename FullEventHierarchyHelper<EventT, std::tuple<BaseTail...>>::type;

        template <typename Tuple1, typename Tuple2>
        struct TupleConcat;

        template <typename... Ts1, typename... Ts2>
        struct TupleConcat<std::tuple<Ts1...>, std::tuple<Ts2...>> {
            using type = std::tuple<Ts1..., Ts2...>;
        };

        using BasesHierarchy = typename TupleConcat<HeadHierarchy, TailHierarchy>::type;

        template <typename Tuple>
        struct UniqueTuple;

        template <>
        struct UniqueTuple<std::tuple<>> {
            using type = std::tuple<>;
        };

        template <typename T, typename... Ts>
        struct UniqueTuple<std::tuple<T, Ts...>> {
        private:
            using TailUnique = typename UniqueTuple<std::tuple<Ts...>>::type;

            template <typename U, typename Tuple>
            struct Contains;

            template <typename U>
            struct Contains<U, std::tuple<>> : std::false_type {};

            template <typename U, typename Head, typename... Rest>
            struct Contains<U, std::tuple<Head, Rest...>> :
                std::conditional_t<std::is_same_v<U, Head>, std::true_type, Contains<U, std::tuple<Rest...>>> {
            };

        public:
            using type = std::conditional_t<
                Contains<T, TailUnique>::value,
                TailUnique,
                Prepend_t<T, TailUnique>
            >;
        };

        using UniqueBasesHierarchy = typename UniqueTuple<BasesHierarchy>::type;

    public:
        using type = Prepend_t<EventT, UniqueBasesHierarchy>;
    };

    template <typename EventT>
    using FullEventHierarchy = typename FullEventHierarchyHelper<EventT>::type;

    template <typename Tuple, std::size_t... I>
    constexpr auto TupleToArrayImpl(std::index_sequence<I...>) {
        return std::array<std::type_index, sizeof...(I)>{ std::type_index(typeid(std::tuple_element_t<I, Tuple>))... };
    }

    template <typename Tuple>
    constexpr auto TupleToArray() {
        return TupleToArrayImpl<Tuple>(std::make_index_sequence<std::tuple_size_v<Tuple>>{});
    }

    class EventHierarchyCache {
    public:
        template <typename EventT>
        static const std::vector<std::type_index>& Get() {
            static const auto arr = TupleToArray<FullEventHierarchy<EventT>>();
            static const std::vector<std::type_index> vec(arr.begin(), arr.end());
            return vec;
        }

        static const std::vector<std::type_index>& Get(std::type_index type) {
            static std::unordered_map<std::type_index, std::vector<std::type_index>> cache;
            static std::mutex mutex;

            {
                std::lock_guard lock(mutex);
                auto it = cache.find(type);
                if (it != cache.end()) return it->second;
            }

            // No compile-time info for unknown type, fallback to self only
            std::vector<std::type_index> vec{ type };

            {
                std::lock_guard lock(mutex);
                cache[type] = vec;
            }

            return cache[type];
        }
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_EVENT_HIERARCHY_H
