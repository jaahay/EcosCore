// /src/ecoscore/language/textrepresentation/UTF8.ixx
export module ecoscore.language.textrepresentation.UTF8;

import ecoscore.language.Encodings;
#include <string_view>
namespace ecoscore::language::textrepresentation {

    struct UTF8 final : Encoding<UTF8> {
        constexpr UTF8() noexcept = default;
        constexpr ~UTF8() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF8";
        }
    };

}
