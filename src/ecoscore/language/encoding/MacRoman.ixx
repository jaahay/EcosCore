// /src/ecoscore/language/encoding/MacRoman.ixx
export module ecoscore.language.encoding.MacRoman;

import std;

import ecoscore.language.Encodings;

namespace ecoscore::language::encoding {

    struct MacRoman final : Encoding<MacRoman> {
        constexpr MacRoman() noexcept = default;
        constexpr ~MacRoman() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "MacRoman";
        }
    };

}
