// File: ecoscore/language/lang/De.h
#ifndef ECOSCORE_LANGUAGE_LANG_DE_H_
#define ECOSCORE_LANGUAGE_LANG_DE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct De final : ecoscore::category::Member<De, ecoscore::language::Language> {
        friend ecoscore::category::Member<De, ecoscore::language::Language>;

    private:
        constexpr De() noexcept = default;
        ~De() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "de"; }

        static constexpr const De& instance() noexcept {
            static const De inst{};
            return inst;
        }
    };

    inline constexpr const De& de = De::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_DE_H_
