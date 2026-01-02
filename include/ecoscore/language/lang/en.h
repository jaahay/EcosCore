// File: ecoscore/language/lang/En.h
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H_
#define ECOSCORE_LANGUAGE_LANG_EN_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief English language identity.
     */
    struct En final : ecoscore::category::Member<En, ecoscore::language::Language> {
        friend ecoscore::category::Member<En, ecoscore::language::Language>;

    private:
        constexpr En() noexcept = default;
        ~En() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "en"; }

        static constexpr const En& instance() noexcept {
            static const En inst{};
            return inst;
        }
    };

    inline constexpr const En& en = En::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_EN_H_
