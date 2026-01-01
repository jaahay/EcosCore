// File: ecoscore/language/textrepresentation/UTF8.h
// /src/ecoscore/language/textrepresentation/UTF8.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H
#define ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H

#include "ecoscore/language/Encodings.h"
#include <string_view>
namespace ecoscore::language::textrepresentation {

    struct UTF8 final : Encoding<UTF8> {
        constexpr UTF8() noexcept = default;
        constexpr ~UTF8() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF8";
} // namespace ecoscore::language::textrepresentation
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H
