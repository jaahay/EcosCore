// File: ecoscore/language/textrepresentation/ASCII.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_

#include "TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief ASCII text representation.
     */
    struct ASCII final : ecoscore::category::Member<ASCII, ecoscore::language::TextRepresentation> {
        friend ecoscore::category::Member<ASCII, ecoscore::language::TextRepresentation>;

    private:
        constexpr ASCII() noexcept = default;
        ~ASCII() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ASCII"; }

        static constexpr const ASCII& instance() noexcept {
            static const ASCII inst{};
            return inst;
        }
    };

    inline constexpr const ASCII& ascii = ASCII::instance();

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_
