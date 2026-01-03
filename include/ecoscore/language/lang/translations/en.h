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
#include "ecoscore/language/Translation.h"

#include <string_view>
#include <unordered_map>

namespace ecoscore::language::translations::en {

    /**
     * @brief English language translation container.
     */
    struct En final : ecoscore::category::Member<En, Translation> {
        friend struct ecoscore::category::Member<En, Translation>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

        static constexpr En create() { return En{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "EnglishTranslation";
        }
        static const std::unordered_map<const Language*, NameSet> members;
    };

    inline const std::unordered_map<const Language*, NameSet> En::members{
        { &lang::en,      NameSet{ "English", "EN", "Eng" } },
        { &lang::ar,      NameSet{ "الإنجليزية", "إنجليزي", "اللغة الإنجليزية" } },
        { &lang::de,      NameSet{ "Englisch", "EN" } },
        { &lang::es,      NameSet{ "Inglés", "Idioma inglés" } },
        { &lang::fr,      NameSet{ "Anglais", "Langue anglaise" } },
        { &lang::zh_hans, NameSet{ "英语", "英文" } },
        { &lang::zh_hant, NameSet{ "英語", "英文" } },
        { &lang::ja,      NameSet{ "英語", "英語の言語" } },
        { &lang::ko,      NameSet{ "영어", "영국 영어" } }
    };

    //inline constexpr const En& en = En::instance;

} // namespace ecoscore::language::translations::en

#endif // ECOSCORE_LANGUAGE_TRANSLATIONS_EN_H_
