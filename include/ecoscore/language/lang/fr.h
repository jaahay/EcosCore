// File: ecoscore/language/lang/Fr.h
#ifndef ECOSCORE_LANGUAGE_LANG_FR_H_
#define ECOSCORE_LANGUAGE_LANG_FR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Fr language.
     */
    struct Fr final : ecoscore::category::Member<Fr, Language> {
        friend ecoscore::category::Member<Fr, Language>;

    private:
        constexpr Fr() noexcept = default;
        ~Fr() noexcept = default;

        static constexpr Fr create() { return Fr{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Fr"; }

    };

    inline constexpr const Fr& fr = Fr::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_FR_H_
