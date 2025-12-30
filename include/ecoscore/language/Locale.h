// include/ecoscore/language/Locale.h
#ifndef ECOSCORE_LANGUAGE_LOCALE_H
#define ECOSCORE_LANGUAGE_LOCALE_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/concepts/Category.h"
#include "ecoscore/language/concepts/Locale.h"
#include "ecoscore/language/TextRepresentations.h"  // For TextRepresentation
#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Locale tag combining language, optional region, and charset.
     *
     * Now includes charset as a TextRepresentation reference.
     */
    struct Locale : tag::concepts::Category<Locale> {
        using language_type = Languages::Language;
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
    static constexpr Locale en_US{ language::lang::En::instance, "US", UTF8::instance() };
    static constexpr Locale fr_FR{ language::lang::Fr::instance, "FR", UTF8::instance() };

}  // namespace ecoscore::language

static_assert(concepts::Locale<ecoscore::language::Locale>, "Locale must satisfy Locale concept");

#endif  // ECOSCORE_LANGUAGE_LOCALE_H
