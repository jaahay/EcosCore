// File: ecoscore/language/lang/ar.h
//// File: EcosCore/src/ecoscore/language/lang/ar.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_AR_H
#define ECOSCORE_LANGUAGE_LANG_AR_H




#include "ecoscore/language/Language.h"
#include "ecoscore/category/Member.h"

namespace ecoscore::language::lang {

struct Ar final : ecoscore::category::Member<Ar, ecoscore::language::Language> {
        friend ecoscore::category::Member<Ar, ecoscore::language::Language>;

    private:
        constexpr Ar() noexcept = default;
        ~Ar() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "ar"; }
    };

inline constexpr auto& ar = Ar::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_AR_H
