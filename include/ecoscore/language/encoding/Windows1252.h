// include/ecoscore/language/encoding/Windows1252.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H
#define ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H

#include "Encoding.h"
#include <string_view>

namespace ecoscore::language::encoding {

    /**
     * @brief Windows-1252 encoding.
     */
    struct Windows1252 final : language::Encoding<Windows1252> {
        friend tag::concepts::Category<Windows1252>;

    protected:
        constexpr Windows1252() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Windows-1252";
        }

        static constexpr Windows1252 instance{};
    };

}  // namespace ecoscore::language::encoding

#endif  // ECOSCORE_LANGUAGE_ENCODING_WINDOWS1252_H
