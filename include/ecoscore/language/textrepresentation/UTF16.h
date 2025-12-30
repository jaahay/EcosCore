// include/ecoscore/language/textrepresentation/UTF16.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H

#include "TextRepresentation.h"
#include <string_view>

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF-16 text representation.
     */
    struct UTF16 final : language::TextRepresentation<UTF16> {
        friend tag::concepts::Category<UTF16>;

    protected:
        constexpr UTF16() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "UTF-16";
        }

        static constexpr UTF16 instance{};
    };

}  // namespace ecoscore::language::textrepresentation

#endif  // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H
