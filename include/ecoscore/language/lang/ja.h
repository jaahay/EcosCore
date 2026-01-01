// File: ecoscore/language/lang/ja.h
//// File: EcosCore/src/ecoscore/language/lang/ja.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_JA_H
#define ECOSCORE_LANGUAGE_LANG_JA_H

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Ja final : Member<Ja, ecoscore::language::Language> {
        friend Member<Ja, ecoscore::language::Language>;

    private:
        constexpr Ja() noexcept = default;
        ~Ja() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "ja"; }
    };

inline constexpr auto& ja = Ja::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_JA_H
