// File: ecoscore/language/lang/zh_hant.h
//// File: EcosCore/src/ecoscore/language/lang/zh_hant.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_ZH_HANT_H
#define ECOSCORE_LANGUAGE_LANG_ZH_HANT_H



#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Zh_hant final : ecoscore::category::Member<Zh_hant, ecoscore::language::Language> {
        friend ecoscore::category::Member<Zh_hant, ecoscore::language::Language>;

    private:
        constexpr Zh_hant() noexcept = default;
        ~Zh_hant() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "zh_hant"; }
    };

inline constexpr auto& zh_hant = Zh_hant::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_ZH_HANT_H
