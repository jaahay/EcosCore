// File: ecoscore/language/lang/zh_hans.h
//// File: EcosCore/src/ecoscore/language/lang/zh_hans.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_LANG_ZH_HANS_H
#define ECOSCORE_ECOSCORE_LANGUAGE_LANG_ZH_HANS_H

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Zh_hans final : Member<Zh_hans, ecoscore::language::Language> {
        friend Member<Zh_hans, ecoscore::language::Language>;

    private:
        constexpr Zh_hans() noexcept = default;
        ~Zh_hans() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "zh_hans"; }
    };

inline constexpr auto& zh_hans = Zh_hans::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_ECOSCORE_LANGUAGE_LANG_ZH_HANS_H
