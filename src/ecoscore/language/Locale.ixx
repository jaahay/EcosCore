// /src/ecoscore/language/Locale.ixx
export module ecoscore.language.Locale;

import ecoscore.language.Languages;
import ecoscore.tag.concepts.Category;
import ecoscore.language.TextRepresentations;
import <string_view>;

namespace ecoscore::language {

    /**
     * @brief Locale tag combining language, optional region, and charset.
     *
     * Now includes charset as a TextRepresentation reference.
     */
    export struct Locale : tag::concepts::Category<Locale> {
        using language_type = Language<Locale>; // or your Languages::Language if defined differently
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
