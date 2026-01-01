// /src/ecoscore/language/encoding/Windows1252.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_IXX__
#define __SRC_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_IXX__

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct Windows1252 final : Encoding<Windows1252> {
        constexpr Windows1252() noexcept = default;
        constexpr ~Windows1252() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Windows1252";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_IXX__
