// include/ecoscore/language/encoding/MacRoman.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H
#define ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H

#include "Encoding.h"
#include <string_view>

namespace ecoscore::language::encoding {

    /**
     * @brief MacRoman encoding.
     */
    struct MacRoman final : language::Encoding<MacRoman> {
        friend tag::concepts::Category<MacRoman>;

    protected:
        constexpr MacRoman() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "MacRoman";
        }

        static constexpr MacRoman instance{};
    };

}  // namespace ecoscore::language::encoding

#endif  // ECOSCORE_LANGUAGE_ENCODING_MACROMAN_H
