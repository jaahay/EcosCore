// include/ecoscore/tag/flow/translation/Continue.h
#ifndef ECOSCORE_TAG_FLOW_TRANSLATION_CONTINUE_H
#define ECOSCORE_TAG_FLOW_TRANSLATION_CONTINUE_H

#include "ecoscore/tag/flow/Continue.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/lang.h"
#include <unordered_map>
#include <string_view>
#include <vector>

namespace ecoscore::tag::flow::translation {

    /**
     * @brief Localized names for the Continue tag in supported languages.
     *
     * Keyed by pointer to language singleton.
     */
    inline const std::unordered_map<const language::Languages::Language*, language::NameSet> Continue{
        { &language::lang::En, language::NameSet{
            "Continue",
            { "cont", "proceed", "go on" }
        }},
        { &language::lang::Ar, language::NameSet{
            "استمر",
            { "تابع", "واصل", "استمر" }
        }},
        { &language::lang::De, language::NameSet{
            "Fortsetzen",
            { "weiter", "fortfahren", "gehen" }
        }},
        { &language::lang::Es, language::NameSet{
            "Continuar",
            { "seguir", "proseguir", "continuar" }
        }},
        { &language::lang::Fr, language::NameSet{
            "Continuer",
            { "poursuivre", "continuer", "aller" }
        }},
        { &language::lang::ZhHans, language::NameSet{
            "继续",
            { "继续", "前进", "继续进行" }
        }},
        { &language::lang::ZhHant, language::NameSet{
            "繼續",
            { "繼續", "前進", "繼續進行" }
        }},
        { &language::lang::Ja, language::NameSet{
            "継続",
            { "続ける", "継続する", "進める" }
        }},
        { &language::lang::Ko, language::NameSet{
            "계속",
            { "계속하다", "진행하다", "이어가다" }
        }}
    };

}  // namespace ecoscore::tag::flow::translation

#endif  // ECOSCORE_TAG_FLOW_TRANSLATION_CONTINUE_H
