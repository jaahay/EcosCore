// File: ecoscore/language/lang/Es.h
#ifndef ECOSCORE_LANGUAGE_LANG_ES_H_
#define ECOSCORE_LANGUAGE_LANG_ES_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct Es final : ecoscore::category::Member<Es, ecoscore::language::Language> {
        friend ecoscore::category::Member<Es, ecoscore::language::Language>;

    private:
        constexpr Es() noexcept = default;
        ~Es() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "es"; }

        static constexpr const Es& instance() noexcept {
            static const Es inst{};
            return inst;
        }
    };

    inline constexpr const Es& es = Es::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ES_H_
