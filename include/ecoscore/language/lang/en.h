// include/ecoscore/language/lang/en.h
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H
#define ECOSCORE_LANGUAGE_LANG_EN_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief English language tag.
     */
    struct En final : language::Language<En> {
        friend tag::concepts::Category<En>;

    protected:
        constexpr En() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "English";
        }

        static constexpr En instance{};
    };

    /**
     * @brief Alias for the singleton instance of English.
     */
    inline constexpr En& En = En::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_EN_H
