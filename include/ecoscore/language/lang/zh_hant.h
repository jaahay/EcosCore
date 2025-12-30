// include/ecoscore/language/lang/zh_hant.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZH_HANT_H
#define ECOSCORE_LANGUAGE_LANG_ZH_HANT_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Traditional Chinese language tag.
     */
    struct ZhHant final : language::Language<ZhHant> {
        friend tag::concepts::Category<ZhHant>;

    protected:
        constexpr ZhHant() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Traditional Chinese";
        }

        static constexpr ZhHant instance{};
    };

    /**
     * @brief Alias for the singleton instance of Traditional Chinese.
     */
    inline constexpr ZhHant& ZhHant = ZhHant::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_ZH_HANT_H
