// /src/ecoscore/language/charset/Cyrillic.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_IXX__
#define __SRC_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_IXX__

#include "std.h"

#include "ecoscore/language/Charsets.h"

namespace ecoscore::language::charset {

    struct Cyrillic final : Charset<Cyrillic> {
        constexpr Cyrillic() noexcept = default;
        constexpr ~Cyrillic() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Cyrillic";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_IXX__
