// include/ecoscore/language/textrepresentation/UTF8.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H

#include "TextRepresentation.h"
#include <string_view>

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF-8 text representation.
     */
    struct UTF8 final : language::TextRepresentation<UTF8> {
        friend tag::concepts::Category<UTF8>;

    protected:
        constexpr UTF8() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF-8";
        }

        static constexpr UTF8 instance{};
    };

}  // namespace ecoscore::language::textrepresentation

#endif  // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H
