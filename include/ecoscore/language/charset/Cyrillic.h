// File: ecoscore/language/charset/Cyrillic.h
// /src/ecoscore/language/charset/Cyrillic.ixx
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H
#define ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Cyrillic final : Charset<Cyrillic> {
        constexpr Cyrillic() noexcept = default;
        constexpr ~Cyrillic() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Cyrillic";
} // namespace ecoscore::language::charset
    };

}
#endif // ECOSCORE_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H
