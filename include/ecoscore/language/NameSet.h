// language/NameSet.h
#ifndef ECOSCORE_LANGUAGE_NAMESET_H
#define ECOSCORE_LANGUAGE_NAMESET_H

#include <string_view>
#include <vector>

namespace ecoscore::language {

    /**
     * @brief Minimal set of localized names for a tag in a locale.
     */
    struct NameSet {
        std::string_view canonical_name;
        std::vector<std::string_view> synonyms;

        constexpr NameSet(std::string_view canonical,
            std::vector<std::string_view> syns = {})
            : canonical_name(canonical), synonyms(std::move(syns)) {
        }
    };

}  // namespace ecoscore::language

#endif  // ECOSCORE_LANGUAGE_NAMESET_H
