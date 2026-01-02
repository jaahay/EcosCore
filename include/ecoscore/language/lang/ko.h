// File: ecoscore/language/lang/Ko.h
#ifndef ECOSCORE_LANGUAGE_LANG_KO_H_
#define ECOSCORE_LANGUAGE_LANG_KO_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct Ko final : ecoscore::category::Member<Ko, ecoscore::language::Language> {
        friend ecoscore::category::Member<Ko, ecoscore::language::Language>;

    private:
        constexpr Ko() noexcept = default;
        ~Ko() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ko"; }

        static constexpr const Ko& instance() noexcept {
            static const Ko inst{};
            return inst;
        }
    };

    inline constexpr const Ko& ko = Ko::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_KO_H_
