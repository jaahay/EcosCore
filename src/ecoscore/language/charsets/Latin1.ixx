// /src/ecoscore/language/charset/Latin1.ixx
export module ecoscore.language.charset.Latin1;

import ecoscore.language.Charsets;
import <string_view>;

namespace ecoscore::language::charset {

    struct Latin1 final : Charset<Latin1> {
        constexpr Latin1() noexcept = default;
        constexpr ~Latin1() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Latin1";
        }
    };

}
