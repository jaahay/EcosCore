// File: ecoscore/language/textrepresentation/ASCII.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief ASCII character set.
     */
    struct ASCII final : ecoscore::category::Member<ASCII, TextRepresentation> {
        friend ecoscore::category::Member<ASCII, TextRepresentation>;

    private:
        constexpr ASCII() noexcept = default;
        ~ASCII() noexcept = default;

        static constexpr ASCII create() { return ASCII{}; }
    public:
        static constexpr std::string_view name() noexcept { return "ASCII"; }

    };

    inline constexpr const ASCII& ascii = ASCII::instance;

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ASCII_H_
