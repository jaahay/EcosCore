// File: ecoscore/language/textrepresentation/UTF8.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_

#include "TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF-8 text representation.
     */
    struct UTF8 final : ecoscore::category::Member<UTF8, ecoscore::language::TextRepresentation> {
        friend ecoscore::category::Member<UTF8, ecoscore::language::TextRepresentation>;

    private:
        constexpr UTF8() noexcept = default;
        ~UTF8() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "UTF-8"; }

        static constexpr const UTF8& instance() noexcept {
            static const UTF8 inst{};
            return inst;
        }
    };

    inline constexpr const UTF8& utf8 = UTF8::instance();

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_
