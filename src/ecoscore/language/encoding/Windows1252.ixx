// /src/ecoscore/language/encoding/Windows1252.ixx
export module ecoscore.language.encoding.Windows1252;

import std;

import ecoscore.language.Encodings;

namespace ecoscore::language::encoding {

    struct Windows1252 final : Encoding<Windows1252> {
        constexpr Windows1252() noexcept = default;
        constexpr ~Windows1252() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Windows1252";
        }
    };

}
