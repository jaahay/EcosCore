// File: ecoscore/language/encoding/Windows1252.h
// /src/ecoscore/language/encoding/Windows1252.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H
#define ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct Windows1252 final : Encoding<Windows1252> {
        constexpr Windows1252() noexcept = default;
        constexpr ~Windows1252() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Windows1252";
} // namespace ecoscore::language::encoding
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H
