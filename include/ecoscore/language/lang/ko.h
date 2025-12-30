// include/ecoscore/language/lang/ko.h
#ifndef ECOSCORE_LANGUAGE_LANG_KO_H
#define ECOSCORE_LANGUAGE_LANG_KO_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Korean language tag.
     */
    struct Ko final : language::Language<Ko> {
        friend tag::concepts::Category<Ko>;

    protected:
        constexpr Ko() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Korean";
        }

        static constexpr Ko instance{};
    };

    /**
     * @brief Alias for the singleton instance of Korean.
     */
    inline constexpr Ko& Ko = Ko::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_KO_H
