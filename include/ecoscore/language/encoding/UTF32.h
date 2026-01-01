// /src/ecoscore/language/encoding/UTF32.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_ENCODING_UTF32_IXX__
#define __SRC_ECOSCORE_LANGUAGE_ENCODING_UTF32_IXX__

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct UTF32 final : Encoding<UTF32> {
        constexpr UTF32() noexcept = default;
        constexpr ~UTF32() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF32";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_ENCODING_UTF32_IXX__
