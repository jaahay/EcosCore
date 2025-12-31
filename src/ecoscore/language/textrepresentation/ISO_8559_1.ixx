// /src/ecoscore/language/textrepresentation/ISO_8859_1.ixx
export module ecoscore.language.textrepresentation.ISO_8859_1;

import ecoscore.language.Encodings;
#include <string_view>

namespace ecoscore::language::textrepresentation {

    struct ISO_8859_1 final : Encoding<ISO_8859_1> {
        constexpr ISO_8859_1() noexcept = default;
        constexpr ~ISO_8859_1() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "ISO_8859_1";
        }
    };

}
