// File: ecoscore/language/charset/Emoji.h
// /src/ecoscore/language/charset/Emoji.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_EMOJI_H
#define ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_EMOJI_H

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Emoji final : Charset<Emoji> {
        constexpr Emoji() noexcept = default;
        constexpr ~Emoji() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Emoji";
} // namespace ecoscore::language::charset
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_EMOJI_H
