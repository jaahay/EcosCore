// File: ecoscore/category/flow/translations/Continue.h
// /src/ecoscore/category/flow/translations/Continue.ixx
#ifndef ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H
#define ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H

#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/lang/En.h"
#include "ecoscore/language/lang/Fr.h"
#include "ecoscore/language/lang/De.h"
#include "ecoscore/language/lang/Es.h"
#include "ecoscore/language/lang/ZhHans.h"
#include "ecoscore/language/lang/ZhHant.h"
#include "ecoscore/language/lang/Ja.h"
#include "ecoscore/language/lang/Ko.h"
#include "ecoscore/language/lang/Ar.h"

#include "ecoscore/language/translation/Translation.h"
#include "ecoscore/category/flow/Continue.h"

#include <unordered_map>
#include <string_view>

namespace ecoscore::category::flow::translations {

    using namespace ecoscore::language;
    using namespace ecoscore::language::lang;
    using namespace ecoscore::language::translation;
    using namespace ecoscore::category::flow;

    struct Continue final : Translation<Continue> {
        constexpr Continue() noexcept = default;
        constexpr ~Continue() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "ContinueTranslation";
} // namespace ecoscore::category::flow::translations

        const std::unordered_map<const Languages::Language*, NameSet> translations{
            { &En, NameSet{ "Continue", "Go on", "Proceed" } },
            { &Fr, NameSet{ "Continuer", "Poursuivre" } },
            { &De, NameSet{ "Fortsetzen", "Weiter" } },
            { &Es, NameSet{ "Continuar", "Seguir" } },
            { &ZhHans, NameSet{ "继续", "持续" } },
            { &ZhHant, NameSet{ "繼續", "持續" } },
            { &Ja, NameSet{ "続ける", "継続" } },
            { &Ko, NameSet{ "계속", "이어가다" } },
            { &Ar, NameSet{ "استمر", "واصل" } }
        };

        [[nodiscard]] const NameSet& get(const Languages::Language& lang) const noexcept {
            auto it = translations.find(&lang);
            if (it != translations.end()) {
                return it->second;
            }
            static constexpr NameSet fallback{ "Continue (translation unavailable)" };
            return fallback;
        }
    };

constexpr Continue ContinueInstance{};

}
#endif // ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H
