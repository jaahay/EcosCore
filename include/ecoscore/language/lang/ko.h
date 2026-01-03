// File: ecoscore/language/lang/Ko.h
#ifndef ECOSCORE_LANGUAGE_LANG_KO_H_
#define ECOSCORE_LANGUAGE_LANG_KO_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Ko language.
     */
    struct Ko final : ecoscore::category::Member<Ko, Language> {
        friend ecoscore::category::Member<Ko, Language>;

    private:
        constexpr Ko() noexcept = default;
        ~Ko() noexcept = default;

        static constexpr Ko create() { return Ko{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Ko"; }

    };

    inline constexpr const Ko& ko = Ko::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_KO_H_
