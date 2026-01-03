// File: ecoscore/language/lang/Es.h
#ifndef ECOSCORE_LANGUAGE_LANG_ES_H_
#define ECOSCORE_LANGUAGE_LANG_ES_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief Es language.
     */
    struct Es final : ecoscore::category::Member<Es, Language> {
        friend ecoscore::category::Member<Es, Language>;

    private:
        constexpr Es() noexcept = default;
        ~Es() noexcept = default;

        static constexpr Es create() { return Es{}; }
    public:
        static constexpr std::string_view name() noexcept { return "Es"; }

    };

    inline constexpr const Es& es = Es::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ES_H_
