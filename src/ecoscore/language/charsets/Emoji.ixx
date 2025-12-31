// /src/ecoscore/language/charset/Emoji.ixx
export module ecoscore.language.charset.Emoji;

import ecoscore.language.Charsets;
import <string_view>;

namespace ecoscore::language::charset {

    struct Emoji final : Charset<Emoji> {
        constexpr Emoji() noexcept = default;
        constexpr ~Emoji() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Emoji";
        }
    };

}
