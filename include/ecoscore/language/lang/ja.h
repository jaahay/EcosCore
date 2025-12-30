// include/ecoscore/language/lang/ja.h
#ifndef ECOSCORE_LANGUAGE_LANG_JA_H
#define ECOSCORE_LANGUAGE_LANG_JA_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Japanese language tag.
     */
    struct Ja final : language::Language<Ja> {
        friend tag::concepts::Category<Ja>;

    protected:
        constexpr Ja() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Japanese";
        }

        static constexpr Ja instance{};
    };

    /**
     * @brief Alias for the singleton instance of Japanese.
     */
    inline constexpr Ja& Ja = Ja::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_JA_H
