// /src/ecoscore/category/flow/translations/Continue.ixx
export module ecoscore.category.flow.translations.Continue;

import ecoscore.language.NameSet;
import ecoscore.language.lang.En;
import ecoscore.language.lang.Fr;
import ecoscore.language.lang.De;
import ecoscore.language.lang.Es;
import ecoscore.language.lang.ZhHans;
import ecoscore.language.lang.ZhHant;
import ecoscore.language.lang.Ja;
import ecoscore.language.lang.Ko;
import ecoscore.language.lang.Ar;

import ecoscore.language.translation.Translation;
import ecoscore.category.flow.Continue;

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
        }

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

    export constexpr Continue ContinueInstance{};

}
