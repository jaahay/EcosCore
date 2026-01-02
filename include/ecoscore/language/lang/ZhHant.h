// File: ecoscore/language/lang/ZhHant.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZHHANT_H_
#define ECOSCORE_LANGUAGE_LANG_ZHHANT_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct ZhHant final : ecoscore::category::Member<ZhHant, ecoscore::language::Language> {
        friend ecoscore::category::Member<ZhHant, ecoscore::language::Language>;

    private:
        constexpr ZhHant() noexcept = default;
        ~ZhHant() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "zh-Hant"; }

        static constexpr const ZhHant& instance() noexcept {
            static const ZhHant inst{};
            return inst;
        }
    };

    inline constexpr const ZhHant& zh_hant = ZhHant::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ZHHANT_H_
