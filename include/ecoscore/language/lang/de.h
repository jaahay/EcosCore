// File: ecoscore/language/lang/de.h
//// File: EcosCore/src/ecoscore/language/lang/de.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_LANG_DE_H
#define ECOSCORE_ECOSCORE_LANGUAGE_LANG_DE_H

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct De final : Member<De, ecoscore::language::Language> {
        friend Member<De, ecoscore::language::Language>;

    private:
        constexpr De() noexcept = default;
        ~De() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "de"; }
    };

inline constexpr auto& de = De::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_ECOSCORE_LANGUAGE_LANG_DE_H
