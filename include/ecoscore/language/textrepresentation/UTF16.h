// File: ecoscore/language/textrepresentation/UTF16.h
// /src/ecoscore/language/textrepresentation/UTF16.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H
#define ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H

#include "ecoscore/language/Encodings.h"
#include <string_view>

namespace ecoscore::language::textrepresentation {

    struct UTF16 final : Encoding<UTF16> {
        constexpr UTF16() noexcept = default;
        constexpr ~UTF16() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF16";
} // namespace ecoscore::language::textrepresentation
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H
