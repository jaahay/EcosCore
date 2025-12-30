// include/ecoscore/language/charset/Emoji.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_EMOJI_H
#define ECOSCORE_LANGUAGE_CHARSET_EMOJI_H

#include "Charset.h"
#include <string_view>

namespace ecoscore::language::charset {

    /**
     * @brief Emoji charset.
     */
    struct Emoji final : language::Charset<Emoji> {
        friend tag::concepts::Category<Emoji>;

    protected:
        constexpr Emoji() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Emoji";
        }

        static constexpr Emoji instance{};
    };

}  // namespace ecoscore::language::charset

#endif  // ECOSCORE_LANGUAGE_CHARSET_EMOJI_H
