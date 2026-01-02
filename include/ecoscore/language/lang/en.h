// File: ecoscore/language/lang/en.h
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H
#define ECOSCORE_LANGUAGE_LANG_EN_H

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct En final : ecoscore::category::Member<En, ecoscore::language::Language> {
        friend ecoscore::category::Member<En, ecoscore::language::Language>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "en"; }
    };

inline constexpr auto& en = En::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_EN_H
