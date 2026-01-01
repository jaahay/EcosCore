// /src/ecoscore/language/encoding/MacRoman.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_IXX__
#define __SRC_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_IXX__

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct MacRoman final : Encoding<MacRoman> {
        constexpr MacRoman() noexcept = default;
        constexpr ~MacRoman() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "MacRoman";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_IXX__
