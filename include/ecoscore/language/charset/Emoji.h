// /src/ecoscore/language/charset/Emoji.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_CHARSET_EMOJI_IXX__
#define __SRC_ECOSCORE_LANGUAGE_CHARSET_EMOJI_IXX__

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Emoji final : Charset<Emoji> {
        constexpr Emoji() noexcept = default;
        constexpr ~Emoji() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Emoji";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_CHARSET_EMOJI_IXX__
