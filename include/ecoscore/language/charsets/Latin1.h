// include/ecoscore/language/charset/Latin1.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_LATIN1_H
#define ECOSCORE_LANGUAGE_CHARSET_LATIN1_H

#include "Charset.h"
#include <string_view>

namespace ecoscore::language::charset {

    /**
     * @brief Latin1 charset (ISO-8859-1).
     */
    struct Latin1 final : language::Charset<Latin1> {
        friend tag::concepts::Category<Latin1>;

    protected:
        constexpr Latin1() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Latin1";
        }

        static constexpr Latin1 instance{};
    };

}  // namespace ecoscore::language::charset

#endif  // ECOSCORE_LANGUAGE_CHARSET_LATIN1_H
