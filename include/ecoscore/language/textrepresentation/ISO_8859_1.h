// File: ecoscore/language/textrepresentation/ISO_8859_1.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_

#include "TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief ISO 8859-1 (Latin-1) text representation.
     */
    struct ISO_8859_1 final : ecoscore::category::Member<ISO_8859_1, ecoscore::language::TextRepresentation> {
        friend ecoscore::category::Member<ISO_8859_1, ecoscore::language::TextRepresentation>;

    private:
        constexpr ISO_8859_1() noexcept = default;
        ~ISO_8859_1() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "ISO-8859-1"; }

        static constexpr const ISO_8859_1& instance() noexcept {
            static const ISO_8859_1 inst{};
            return inst;
        }
    };

    inline constexpr const ISO_8859_1& iso_8859_1 = ISO_8859_1::instance();

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_
