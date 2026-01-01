// File: ecoscore/language/lang/ar.h
//// File: EcosCore/src/ecoscore/language/lang/ar.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_LANG_AR_H
#define ECOSCORE_ECOSCORE_LANGUAGE_LANG_AR_H

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/language/Language.h"
#include "ecoscore/category/Member.h"

namespace ecoscore::language::lang {

struct Ar final : Member<Ar, ecoscore::language::Language> {
        friend Member<Ar, ecoscore::language::Language>;

    private:
        constexpr Ar() noexcept = default;
        ~Ar() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "ar"; }
    };

inline constexpr auto& ar = Ar::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_ECOSCORE_LANGUAGE_LANG_AR_H
