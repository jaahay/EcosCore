// /src/ecoscore/language/textrepresentation/UTF16.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_IXX__
#define __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_IXX__

#include "ecoscore/language/Encodings.h"
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
#endif // __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_IXX__
