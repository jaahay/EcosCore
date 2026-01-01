//// File: EcosCore/src/ecoscore/language/lang/ko.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANG_KO_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANG_KO_IXX__

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Ko final : Member<Ko, ecoscore::language::Language> {
        friend Member<Ko, ecoscore::language::Language>;

    private:
        constexpr Ko() noexcept = default;
        ~Ko() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "ko"; }
    };

inline constexpr auto& ko = Ko::instance();

} // namespace ecoscore::language::lang
#endif // __SRC_ECOSCORE_LANGUAGE_LANG_KO_IXX__
