// /src/ecoscore/language/charset/Latin1.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_CHARSET_LATIN1_IXX__
#define __SRC_ECOSCORE_LANGUAGE_CHARSET_LATIN1_IXX__

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Latin1 final : Charset<Latin1> {
        constexpr Latin1() noexcept = default;
        constexpr ~Latin1() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Latin1";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_CHARSET_LATIN1_IXX__
