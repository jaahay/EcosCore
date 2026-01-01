// /src/ecoscore/language/Locale.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LOCALE_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LOCALE_IXX__

#include "std.h"

#include "ecoscore/language/Langs.h"
#include "ecoscore/language/Languages.h"
#include "ecoscore/language/TextRepresentations.h"

#include "ecoscore/category/Category.h"

namespace ecoscore::language {

    /**
     * @brief Locale category combining language, optional region, and charset.
     *
     * Now includes charset as a TextRepresentation reference.
     */
struct Locale : ecoscore::category::Category<Locale> {
        using language_type = Language<Locale>; // or your Languages::Language if defined differently
        using charset_type = ecoscore::language::TextRepresentation;

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
    static constexpr Locale en_US{ &ecoscore::language::En, "US", &ecoscore::language::UTF8 };
    static constexpr Locale fr_FR{ &ecoscore::language::Fr, "FR", &ecoscore::language::UTF8 };

}  // namespace ecoscore::language
#endif // __SRC_ECOSCORE_LANGUAGE_LOCALE_IXX__
