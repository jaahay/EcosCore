// File: ecoscore/language/lang/Zh_hant.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZH_HANT_H_
#define ECOSCORE_LANGUAGE_LANG_ZH_HANT_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Zh_hant language.
     */
    struct Zh_hant final : ecoscore::category::Member<Zh_hant, Language> {
        friend ecoscore::category::Member<Zh_hant, Language>;

    private:
        constexpr Zh_hant() noexcept = default;
        ~Zh_hant() noexcept = default;

        static constexpr Zh_hant create() { return Zh_hant{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Zh_hant"; }

    };

    inline constexpr const Zh_hant& zh_hant = Zh_hant::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ZH_HANT_H_
