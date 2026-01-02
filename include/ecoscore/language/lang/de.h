// File: ecoscore/language/lang/de.h
//// File: EcosCore/src/ecoscore/language/lang/de.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_DE_H
#define ECOSCORE_LANGUAGE_LANG_DE_H

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct De final : ecoscore::category::Member<De, ecoscore::language::Language> {
        friend ecoscore::category::Member<De, ecoscore::language::Language>;

    private:
        constexpr De() noexcept = default;
        ~De() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "de"; }
    };

inline constexpr auto& de = De::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_DE_H
