// /src/ecoscore/language/textrepresentation/ISO_8859_1.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_IXX__
#define __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_IXX__

#include "ecoscore/language/Encodings.h"
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
#endif // __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_IXX__
