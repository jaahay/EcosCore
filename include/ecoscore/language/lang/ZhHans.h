// File: ecoscore/language/lang/ZhHans.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZHHANS_H_
#define ECOSCORE_LANGUAGE_LANG_ZHHANS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/Language.h"

#include <string_view>

namespace ecoscore::language::lang {

    struct ZhHans final : ecoscore::category::Member<ZhHans, ecoscore::language::Language> {
        friend ecoscore::category::Member<ZhHans, ecoscore::language::Language>;

    private:
        constexpr ZhHans() noexcept = default;
        ~ZhHans() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "zh-Hans"; }

        static constexpr const ZhHans& instance() noexcept {
            static const ZhHans inst{};
            return inst;
        }
    };

    inline constexpr const ZhHans& zh_hans = ZhHans::instance();

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ZHHANS_H_
