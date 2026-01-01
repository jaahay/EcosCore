// File: ecoscore/language/lang/en.h
//// File: EcosCore/src/ecoscore/language/lang/en.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H
#define ECOSCORE_LANGUAGE_LANG_EN_H

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct En final : Member<En, ecoscore::language::Language> {
        friend Member<En, ecoscore::language::Language>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "en"; }
    };

inline constexpr auto& en = En::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_EN_H
