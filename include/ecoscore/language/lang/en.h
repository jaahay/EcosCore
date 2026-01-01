//// File: EcosCore/src/ecoscore/language/lang/en.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANG_EN_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANG_EN_IXX__

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
#endif // __SRC_ECOSCORE_LANGUAGE_LANG_EN_IXX__
