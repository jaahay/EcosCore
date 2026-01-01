// File: ecoscore/language/encoding/UTF32.h
// /src/ecoscore/language/encoding/UTF32.ixx
#ifndef ECOSCORE_LANGUAGE_ENCODING_UTF32_H
#define ECOSCORE_LANGUAGE_ENCODING_UTF32_H

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct UTF32 final : Encoding<UTF32> {
        constexpr UTF32() noexcept = default;
        constexpr ~UTF32() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF32";
} // namespace ecoscore::language::encoding
    };

}
#endif // ECOSCORE_LANGUAGE_ENCODING_UTF32_H
