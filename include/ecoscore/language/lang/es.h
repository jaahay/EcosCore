//// File: EcosCore/src/ecoscore/language/lang/es.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANG_ES_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANG_ES_IXX__

#include "std.h"
#include "std/string_view.h"

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Es final : Member<Es, ecoscore::language::Language> {
        friend Member<Es, ecoscore::language::Language>;

    private:
        constexpr Es() noexcept = default;
        ~Es() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "es"; }
    };

inline constexpr auto& es = Es::instance();

} // namespace ecoscore::language::lang
#endif // __SRC_ECOSCORE_LANGUAGE_LANG_ES_IXX__
