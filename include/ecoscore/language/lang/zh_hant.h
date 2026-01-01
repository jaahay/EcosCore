//// File: EcosCore/src/ecoscore/language/lang/zh_hant.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANG_ZH_HANT_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANG_ZH_HANT_IXX__

#include "std.h"
#include "std/string_view.h"
#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Zh_hant final : Member<Zh_hant, ecoscore::language::Language> {
        friend Member<Zh_hant, ecoscore::language::Language>;

    private:
        constexpr Zh_hant() noexcept = default;
        ~Zh_hant() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "zh_hant"; }
    };

inline constexpr auto& zh_hant = Zh_hant::instance();

} // namespace ecoscore::language::lang
#endif // __SRC_ECOSCORE_LANGUAGE_LANG_ZH_HANT_IXX__
