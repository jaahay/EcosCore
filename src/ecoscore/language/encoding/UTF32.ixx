// /src/ecoscore/language/encoding/UTF32.ixx
export module ecoscore.language.encoding.UTF32;

import std;

import ecoscore.language.Encodings;

namespace ecoscore::language::encoding {

    struct UTF32 final : Encoding<UTF32> {
        constexpr UTF32() noexcept = default;
        constexpr ~UTF32() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF32";
        }
    };

}
