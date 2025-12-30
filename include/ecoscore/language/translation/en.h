// include/ecoscore/language/translation/en.h
#ifndef ECOSCORE_LANGUAGE_TRANSLATION_EN_H
#define ECOSCORE_LANGUAGE_TRANSLATION_EN_H

#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/lang.h"
#include <unordered_map>
#include <string_view>
#include <vector>

namespace ecoscore::language::translation::en {

    /**
     * @brief Localized names for the English language identity,
     * keyed by pointer to language singleton.
     */
    inline const std::unordered_map<const language::Languages::Language*, language::NameSet> EnglishTranslations{
        { &language::lang::En, language::NameSet{
            "English",
            { "English", "EN", "Eng" }
        }},
        { &language::lang::Ar, language::NameSet{
            "الإنجليزية",
            { "إنجليزي", "اللغة الإنجليزية" }
        }},
        { &language::lang::De, language::NameSet{
            "Englisch",
            { "Englisch", "EN" }
        }},
        { &language::lang::Es, language::NameSet{
            "Inglés",
            { "Inglés", "Idioma inglés" }
        }},
        { &language::lang::Fr, language::NameSet{
            "Anglais",
            { "Anglais", "Langue anglaise" }
        }},
        { &language::lang::ZhHans, language::NameSet{
            "英语",
            { "英语", "英文" }
        }},
        { &language::lang::ZhHant, language::NameSet{
            "英語",
            { "英語", "英文" }
        }},
        { &language::lang::Ja, language::NameSet{
            "英語",
            { "英語", "英語の言語" }
        }},
        { &language::lang::Ko, language::NameSet{
            "영어",
            { "영어", "영국 영어" }
        }},
    };

}  // namespace ecoscore::language::translation::en

#endif  // ECOSCORE_LANGUAGE_TRANSLATION_EN_H
