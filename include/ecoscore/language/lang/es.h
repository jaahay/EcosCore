// File: ecoscore/language/lang/es.h
//// File: EcosCore/src/ecoscore/language/lang/es.ixx
#ifndef ECOSCORE_LANGUAGE_LANG_ES_H
#define ECOSCORE_LANGUAGE_LANG_ES_H




#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

struct Es final : ecoscore::category::Member<Es, ecoscore::language::Language> {
        friend ecoscore::category::Member<Es, ecoscore::language::Language>;

    private:
        constexpr Es() noexcept = default;
        ~Es() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "es"; }
    };

inline constexpr auto& es = Es::instance();

} // namespace ecoscore::language::lang
#endif // ECOSCORE_LANGUAGE_LANG_ES_H
