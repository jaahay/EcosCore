// File: ecoscore/language/lang/Fr.h
#ifndef ECOSCORE_LANGUAGE_LANG_FR_H_
#define ECOSCORE_LANGUAGE_LANG_FR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct Fr final : ecoscore::category::Member<Fr, ecoscore::language::Language> {
        friend ecoscore::category::Member<Fr, ecoscore::language::Language>;

    private:
        constexpr Fr() noexcept = default;
        ~Fr() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "fr"; }

        static constexpr const Fr& instance() noexcept {
            static const Fr inst{};
            return inst;
        }
    };

    inline constexpr const Fr& fr = Fr::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_FR_H_
