//// File: EcosCore/src/ecoscore/language/lang/fr.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANG_FR_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANG_FR_IXX__

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Fr final : Member<Fr, ecoscore::language::Language> {
        friend Member<Fr, ecoscore::language::Language>;

    private:
        constexpr Fr() noexcept = default;
        ~Fr() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "fr"; }
    };

inline constexpr auto& fr = Fr::instance();

} // namespace ecoscore::language::lang
#endif // __SRC_ECOSCORE_LANGUAGE_LANG_FR_IXX__
