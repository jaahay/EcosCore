// include/ecoscore/language/lang/de.h
#ifndef ECOSCORE_LANGUAGE_LANG_DE_H
#define ECOSCORE_LANGUAGE_LANG_DE_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief German language tag.
     */
    struct De final : language::Language<De> {
        friend tag::concepts::Category<De>;

    protected:
        constexpr De() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "German";
        }

        static constexpr De instance{};
    };

    /**
     * @brief Alias for the singleton instance of German.
     */
    inline constexpr De& De = De::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_DE_H
