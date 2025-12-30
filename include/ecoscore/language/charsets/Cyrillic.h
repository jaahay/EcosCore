// include/ecoscore/language/charset/Cyrillic.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H
#define ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H

#include "Charset.h"
#include <string_view>

namespace ecoscore::language::charset {

    /**
     * @brief Cyrillic charset.
     */
    struct Cyrillic final : language::Charset<Cyrillic> {
        friend tag::concepts::Category<Cyrillic>;

    protected:
        constexpr Cyrillic() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Cyrillic";
        }

        static constexpr Cyrillic instance{};
    };

}  // namespace ecoscore::language::charset

#endif  // ECOSCORE_LANGUAGE_CHARSET_CYRILLIC_H
