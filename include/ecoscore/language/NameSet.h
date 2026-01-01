// File: ecoscore/language/NameSet.h
// /src/ecoscore/language/NameSet.ixx
#ifndef ECOSCORE_LANGUAGE_NAMESET_H
#define ECOSCORE_LANGUAGE_NAMESET_H

#include "std.h"

namespace ecoscore::language {

    /**
     * @brief Immutable set of localized names for a tag in a locale.
     *
     * Holds a canonical name and an arbitrary number of synonyms (excluding the canonical).
     * Provides constexpr iteration over synonyms for compile-time processing.
     */
template <typename... Syns>
        struct NameSet {
        std::string_view canonical_name_;
        std::tuple<std::string_view, Syns...> synonyms_;

        private:
            template <std::size_t Index = 0, typename Func>
            static constexpr void iterate_impl(const std::tuple<std::string_view, Syns...>& t, Func&& func) {
                if constexpr (Index < sizeof...(Syns) + 1) {  // +1 for canonical included in tuple
                    func(std::get<Index>(t));
                    iterate_impl<Index + 1>(t, std::forward<Func>(func));
} // namespace ecoscore::language
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

} //  namespace ecoscore::language
#endif // ECOSCORE_LANGUAGE_NAMESET_H
