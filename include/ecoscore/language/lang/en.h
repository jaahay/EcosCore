// File: ecoscore/language/lang/En.h
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H_
#define ECOSCORE_LANGUAGE_LANG_EN_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief En language.
     */
    struct En final : ecoscore::category::Member<En, Language> {
        friend ecoscore::category::Member<En, Language>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

        static constexpr En create() { return En{}; }
    public:
        static constexpr std::string_view name() noexcept { return "En"; }

    };

    inline constexpr const En& en = En::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_EN_H_
