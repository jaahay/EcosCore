// File: ecoscore/language/charset/Latin1.h
// /src/ecoscore/language/charset/Latin1.ixx
#ifndef ECOSCORE_LANGUAGE_CHARSET_LATIN1_H
#define ECOSCORE_LANGUAGE_CHARSET_LATIN1_H

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Latin1 final : Charset<Latin1> {
        constexpr Latin1() noexcept = default;
        constexpr ~Latin1() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Latin1";
} // namespace ecoscore::language::charset
    };

}
#endif // ECOSCORE_LANGUAGE_CHARSET_LATIN1_H
