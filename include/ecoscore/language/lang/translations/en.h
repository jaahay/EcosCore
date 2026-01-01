// File: ecoscore/language/lang/translations/en.h
// /src/ecoscore/language/translations/en.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_LANG_TRANSLATIONS_EN_H
#define ECOSCORE_ECOSCORE_LANGUAGE_LANG_TRANSLATIONS_EN_H

#include "std.h"

#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/lang/Lang.h"
#include "ecoscore/language/translation/Translation.h"

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
} // namespace ecoscore::language::translations::en

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

constexpr EnglishTranslation EnglishTranslationInstance{};

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_LANG_TRANSLATIONS_EN_H
