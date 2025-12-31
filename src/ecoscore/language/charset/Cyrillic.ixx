// /src/ecoscore/language/charset/Cyrillic.ixx
export module ecoscore.language.charset.Cyrillic;

import std;

import ecoscore.language.Charsets;

namespace ecoscore::language::charset {

    struct Cyrillic final : Charset<Cyrillic> {
        constexpr Cyrillic() noexcept = default;
        constexpr ~Cyrillic() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Cyrillic";
        }
    };

}
