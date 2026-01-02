// File: ecoscore/language/NameSet.h
#ifndef ECOSCORE_LANGUAGE_NAMESET_H_
#define ECOSCORE_LANGUAGE_NAMESET_H_

#include <string_view>
#include <tuple>
#include <utility>

namespace ecoscore::language {

    /**
     * @brief Immutable set of localized names for a tag in a locale.
     *
     * Holds a canonical name and an arbitrary number of synonyms (excluding the canonical).
     * Provides constexpr iteration over synonyms for compile-time processing.
     *
     * @tparam Syns Variadic list of synonym string_view types.
     */
    struct NameSet {
        std::string_view canonical_name_;
        std::array<std::string_view...> synonyms_;

    private:
        template <std::size_t Index = 0, typename Func>
        static constexpr void iterate_impl(const std::tuple<std::string_view, Syns...>& t, Func&& func) {
            if constexpr (Index < sizeof...(Syns) + 1) {  // +1 includes canonical_name_
                func(std::get<Index>(t));
                iterate_impl<Index + 1>(t, std::forward<Func>(func));
            }
        }

    public:
        template <typename Func>
        constexpr void iterate(Func&& func) const {
            iterate_impl<0>(synonyms_, std::forward<Func>(func));
        }

        [[nodiscard]] constexpr std::string_view canonical_name() const noexcept {
            return canonical_name_;
        }

        constexpr NameSet(std::string_view canonical, Syns... syns)
            : canonical_name_(canonical), synonyms_{ canonical, syns... } {
        }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_NAMESET_H_
