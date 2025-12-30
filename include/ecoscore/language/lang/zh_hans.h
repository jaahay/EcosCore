// include/ecoscore/language/lang/zh_hans.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZH_HANS_H
#define ECOSCORE_LANGUAGE_LANG_ZH_HANS_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Simplified Chinese language tag.
     */
    struct ZhHans final : language::Language<ZhHans> {
        friend tag::concepts::Category<ZhHans>;

    protected:
        constexpr ZhHans() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Simplified Chinese";
        }

        static constexpr ZhHans instance{};
    };

    /**
     * @brief Alias for the singleton instance of Simplified Chinese.
     */
    inline constexpr ZhHans& ZhHans = ZhHans::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_ZH_HANS_H
