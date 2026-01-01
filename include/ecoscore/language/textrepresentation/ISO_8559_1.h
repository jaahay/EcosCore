// File: ecoscore/language/textrepresentation/ISO_8559_1.h
// /src/ecoscore/language/textrepresentation/ISO_8859_1.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_H
#define ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_H

#include "ecoscore/language/Encodings.h"
#include <string_view>

namespace ecoscore::language::textrepresentation {

    struct ISO_8859_1 final : Encoding<ISO_8859_1> {
        constexpr ISO_8859_1() noexcept = default;
        constexpr ~ISO_8859_1() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "ISO_8859_1";
} // namespace ecoscore::language::textrepresentation
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8559_1_H
