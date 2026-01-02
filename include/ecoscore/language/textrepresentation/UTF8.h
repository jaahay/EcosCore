// File: ecoscore/language/textrepresentation/UTF16.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_

#include "TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF-16 text representation.
     */
    struct UTF16 final : ecoscore::category::Member<UTF16, ecoscore::language::TextRepresentation> {
        friend ecoscore::category::Member<UTF16, ecoscore::language::TextRepresentation>;

    private:
        constexpr UTF16() noexcept = default;
        ~UTF16() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "UTF-16"; }

        static constexpr const UTF16& instance() noexcept {
            static const UTF16 inst{};
            return inst;
        }
    };

    inline constexpr const UTF16& utf16 = UTF16::instance();

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_
