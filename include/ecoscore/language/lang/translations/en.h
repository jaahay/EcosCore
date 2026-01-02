// File: ecoscore/language/translations/En.h
#ifndef ECOSCORE_LANGUAGE_TRANSLATIONS_EN_H_
#define ECOSCORE_LANGUAGE_TRANSLATIONS_EN_H_

#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/lang/En.h"
#include "ecoscore/language/lang/Ar.h"
#include "ecoscore/language/lang/De.h"
#include "ecoscore/language/lang/Es.h"
#include "ecoscore/language/lang/Fr.h"
#include "ecoscore/language/lang/ZhHans.h"
#include "ecoscore/language/lang/ZhHant.h"
#include "ecoscore/language/lang/Ja.h"
#include "ecoscore/language/lang/Ko.h"
#include "ecoscore/language/translation/Translation.h"

#include <string_view>
#include <unordered_map>

namespace ecoscore::language::translations::en {

    /**
     * @brief English language translation container.
     */
    struct En final : translation::Translation<En> {
        friend translation::Translation<En>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

    public:
        static constexpr std::string_view static_name() noexcept {
            return "EnglishTranslation";
        }

        static const std::unordered_map<const ecoscore::language::Language*, NameSet> members;
    };

    inline const std::unordered_map<const ecoscore::language::Language*, NameSet> En::members{
        { &lang::En::Instance,     NameSet{ "English", "EN", "Eng" } },
        { &lang::Ar::Instance,     NameSet{ "الإنجليزية", "إنجليزي", "اللغة الإنجليزية" } },
        { &lang::De::Instance,     NameSet{ "Englisch", "EN" } },
        { &lang::Es::Instance,     NameSet{ "Inglés", "Idioma inglés" } },
        { &lang::Fr::Instance,     NameSet{ "Anglais", "Langue anglaise" } },
        { &lang::ZhHans::Instance, NameSet{ "英语", "英文" } },
        { &lang::ZhHant::Instance, NameSet{ "英語", "英文" } },
        { &lang::Ja::Instance,     NameSet{ "英語", "英語の言語" } },
        { &lang::Ko::Instance,     NameSet{ "영어", "영국 영어" } }
    };

    inline constexpr En en{};

} // namespace ecoscore::language::translations::en

#endif // ECOSCORE_LANGUAGE_TRANSLATIONS_EN_H_
