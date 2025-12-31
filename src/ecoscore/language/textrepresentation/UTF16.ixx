// /src/ecoscore/language/textrepresentation/UTF16.ixx
export module ecoscore.language.textrepresentation.UTF16;

import ecoscore.language.Encodings;
#include <string_view>

namespace ecoscore::language::textrepresentation {

    struct UTF16 final : Encoding<UTF16> {
        constexpr UTF16() noexcept = default;
        constexpr ~UTF16() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF16";
        }
    };

}
