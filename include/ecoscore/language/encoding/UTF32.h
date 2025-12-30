// include/ecoscore/language/encoding/UTF32.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_UTF32_H
#define ECOSCORE_LANGUAGE_ENCODING_UTF32_H

#include "Encoding.h"
#include <string_view>

namespace ecoscore::language::encoding {

    /**
     * @brief UTF-32 encoding.
     */
    struct UTF32 final : language::Encoding<UTF32> {
        friend tag::concepts::Category<UTF32>;

    protected:
        constexpr UTF32() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF-32";
        }

        static constexpr UTF32 instance{};
    };

}  // namespace ecoscore::language::encoding

#endif  // ECOSCORE_LANGUAGE_ENCODING_UTF32_H
