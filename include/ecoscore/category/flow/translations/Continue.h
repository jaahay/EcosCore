// File: ecoscore/category/flow/translations/Continue.h
#ifndef ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H_
#define ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Flow.h"
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

namespace ecoscore::category::flow::translations {

    /**
     * @brief Continue flow translation member.
     */
    struct Continue final : ecoscore::category::Member<Continue, ecoscore::category::Flow>,
        ecoscore::language::translation::Translation<Continue> {
        friend ecoscore::category::Member<Continue, ecoscore::category::Flow>;
        friend ecoscore::language::translation::Translation<Continue>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ContinueTranslation"; }

        [[nodiscard]] const std::unordered_map<const ecoscore::language::Language*, ecoscore::language::NameSet>& NameSets() const noexcept override {
            static const std::unordered_map<const ecoscore::language::Language*, ecoscore::language::NameSet> translations{
                { &ecoscore::language::lang::en,        ecoscore::language::NameSet{"Continue", "Go On", "Proceed"} },
                { &ecoscore::language::lang::ar,        ecoscore::language::NameSet{"استمر", "تابع"} },
                { &ecoscore::language::lang::de,        ecoscore::language::NameSet{"Fortsetzen", "Weiter"} },
                { &ecoscore::language::lang::es,        ecoscore::language::NameSet{"Continuar", "Seguir"} },
                { &ecoscore::language::lang::fr,        ecoscore::language::NameSet{"Continuer", "Poursuivre"} },
                { &ecoscore::language::lang::zh_hans,   ecoscore::language::NameSet{"继续", "前进"} },
                { &ecoscore::language::lang::zh_hant,   ecoscore::language::NameSet{"繼續", "前進"} },
                { &ecoscore::language::lang::ja,        ecoscore::language::NameSet{"続ける", "進める"} },
                { &ecoscore::language::lang::ko,        ecoscore::language::NameSet{"계속", "진행"} }
            };
            return translations;
        }

        static constexpr const Continue& instance() noexcept {
            static const Continue inst{};
            return inst;
        }
    };

    inline constexpr const Continue& cont = Continue::instance();

} // namespace ecoscore::category::flow::translations

#endif // ECOSCORE_CATEGORY_FLOW_TRANSLATIONS_CONTINUE_H_
