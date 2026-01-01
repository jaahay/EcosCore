// File: ecoscore/language/textrepresentation/ASCII.h
// include/ecoscore/language/textrepresentation/ASCII.h
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H
#define ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H

#include "TextRepresentation.h"
#include <string_view>

namespace ecoscore::language::textrepresentation {

/**
 * @brief ASCII text representation.
 */
struct ASCII final : language::TextRepresentation<ASCII> {
    friend tag::concepts::Category<ASCII>;

protected:
    constexpr ASCII() noexcept = default;

public:
    [[nodiscard]] static constexpr std::string_view static_name() noexcept {
        return "ASCII";
} // namespace ecoscore::language::textrepresentation

    static constexpr ASCII instance{};
};

}  // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H
