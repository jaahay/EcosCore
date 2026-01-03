// File: ecoscore/language/lang/De.h
#ifndef ECOSCORE_LANGUAGE_LANG_DE_H_
#define ECOSCORE_LANGUAGE_LANG_DE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

namespace ecoscore::language::lang {

    /**
     * @brief De language.
     */
    struct De final : ecoscore::category::Member<De, Language> {
        friend ecoscore::category::Member<De, Language>;

    private:
        constexpr De() noexcept = default;
        ~De() noexcept = default;

        static constexpr De create() { return De{}; }
    public:
        static constexpr std::string_view name() noexcept { return "De"; }

    };

    inline constexpr const De& de = De::instance;

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_DE_H_
