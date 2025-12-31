// /src/ecoscore/language/translations/en.ixx
export module ecoscore.language.translations.en;

import ecoscore.language.NameSet;
import ecoscore.language.lang.Lang;          // All nine language tags with aliases
import ecoscore.language.translation.Translation;

import <unordered_map>;
import <string_view>;

namespace ecoscore::language::translations::en {

    using namespace ecoscore::language;
    using namespace ecoscore::language::lang;
    using namespace ecoscore::language::translation;

    /**
     * @brief English language identity translations into multiple languages.
     */
    struct EnglishTranslation final : Translation<EnglishTranslation> {
        constexpr EnglishTranslation() noexcept = default;
        constexpr ~EnglishTranslation() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "EnglishTranslation";
        }

        const std::unordered_map<const Languages::Language*, NameSet> translations{
            { &En,    NameSet{ "English", "EN", "Eng" } },
            { &Ar,    NameSet{ "الإنجليزية", "إنجليزي", "اللغة الإنجليزية" } },
            { &De,    NameSet{ "Englisch", "EN" } },
            { &Es,    NameSet{ "Inglés", "Idioma inglés" } },
            { &Fr,    NameSet{ "Anglais", "Langue anglaise" } },
            { &ZhHans,NameSet{ "英语", "英文" } },
            { &ZhHant,NameSet{ "英語", "英文" } },
            { &Ja,    NameSet{ "英語", "英語の言語" } },
            { &Ko,    NameSet{ "영어", "영국 영어" } }
        };

        [[nodiscard]] const NameSet& get(const Languages::Language& lang) const noexcept {
            auto it = translations.find(&lang);
            if (it != translations.end()) {
                return it->second;
            }
            static constexpr NameSet fallback{ "English (translation unavailable)" };
            return fallback;
        }
    };

    export constexpr EnglishTranslation EnglishTranslationInstance{};

}
