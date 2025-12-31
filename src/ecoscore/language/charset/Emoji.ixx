// /src/ecoscore/language/charset/Emoji.ixx
export module ecoscore.language.charset.Emoji;

import std;

import ecoscore.language.Charsets;

namespace ecoscore::language::charset {

    struct Emoji final : Charset<Emoji> {
        constexpr Emoji() noexcept = default;
        constexpr ~Emoji() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Emoji";
        }
    };

}
