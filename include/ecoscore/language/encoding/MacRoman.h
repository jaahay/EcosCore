// File: ecoscore/language/encoding/MacRoman.h
// /src/ecoscore/language/encoding/MacRoman.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H
#define ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H

#include "std.h"

#include "ecoscore/language/Encodings.h"

namespace ecoscore::language::encoding {

    struct MacRoman final : Encoding<MacRoman> {
        constexpr MacRoman() noexcept = default;
        constexpr ~MacRoman() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "MacRoman";
} // namespace ecoscore::language::encoding
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H
