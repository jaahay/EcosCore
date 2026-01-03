// File: ecoscore/language/Locale.h
#ifndef ECOSCORE_LANGUAGE_LOCALE_H_
#define ECOSCORE_LANGUAGE_LOCALE_H_

#include "ecoscore/language/Lang.h"
#include "ecoscore/language/Language.h"
#include "ecoscore/language/TextRepresentation.h"
#include "ecoscore/category/Category.h"

#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Locale category combining language, optional region, and charset.
     *
     * Now includes charset as a TextRepresentation reference.
     */
    struct Locale : ecoscore::category::Category {
        using language_type = Language; // or your Languages::Language if defined differently
        using charset_type = TextRepresentation;

        constexpr Locale(const language_type& lang,
            std::string_view region = "",
            const charset_type& charset = UTF8::instance())
            : language(lang), region_code(region), charset(charset) {
        }

        const language_type& language;
        std::string_view region_code;
        const charset_type& charset;

        [[nodiscard]] constexpr bool operator==(const Locale& other) const noexcept {
            return &language == &other.language &&
                region_code == other.region_code &&
                &charset == &other.charset;
        }

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Locale";
        }
    };

    // Common locale instances for convenience
    static constexpr Locale en_US{ ecoscore::language::En::Instance, "US", ecoscore::language::UTF8::Instance };
    static constexpr Locale fr_FR{ ecoscore::language::Fr::Instance, "FR", ecoscore::language::UTF8::Instance };

}  // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_LOCALE_H_
