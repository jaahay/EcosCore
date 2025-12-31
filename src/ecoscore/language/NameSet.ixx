// /src/ecoscore/language/NameSet.ixx
export module ecoscore.language.NameSet;

import <string_view>;
import <tuple>;
import <utility>;

namespace ecoscore::language {

    /**
     * @brief Immutable set of localized names for a tag in a locale.
     *
     * Holds a canonical name and an arbitrary number of synonyms (excluding the canonical).
     * Provides constexpr iteration over synonyms for compile-time processing.
     */
    export struct NameSet {
        std::string_view canonical_name;
        std::tuple<std::string_view...> synonyms;

    private:
        template <std::size_t Index = 0, typename Func>
        static constexpr void iterate_impl(const std::tuple<std::string_view...>& t, Func&& func) {
            if constexpr (Index < sizeof...(std::string_view)) {
                func(std::get<Index>(t));
                iterate_impl<Index + 1>(t, std::forward<Func>(func));
            }
        }

    public:
        template <typename Func>
        constexpr void iterate(Func&& func) const {
            iterate_impl<0>(synonyms, std::forward<Func>(func));
        }

        [[nodiscard]] constexpr std::string_view canonical_name() const noexcept {
            return canonical_name;
        }

        template <typename... Syns>
        constexpr NameSet(std::string_view canonical, Syns... syns)
            : canonical_name(canonical), synonyms{ syns... } {
        }
    };

}
