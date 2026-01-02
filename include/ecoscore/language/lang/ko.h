// File: ecoscore/language/lang/ko.h
//// File: EcosCore/src/ecoscore/language/lang/ko.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_KO_H
#define ECOSCORE_LANGUAGE_LANG_KO_H




#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Ko final : ecoscore::category::Member<Ko, ecoscore::language::Language> {
        friend ecoscore::category::Member<Ko, ecoscore::language::Language>;

    private:
        constexpr Ko() noexcept = default;
        ~Ko() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "ko"; }
    };

inline constexpr auto& ko = Ko::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_KO_H
