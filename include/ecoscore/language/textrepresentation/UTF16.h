// File: ecoscore/language/textrepresentation/UTF16.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF16 character set.
     */
    struct UTF16 final : ecoscore::category::Member<UTF16, TextRepresentation> {
        friend ecoscore::category::Member<UTF16, TextRepresentation>;

    private:
        constexpr UTF16() noexcept = default;
        ~UTF16() noexcept = default;

        static constexpr UTF16 create() { return UTF16{}; }
    public:
        static constexpr std::string_view name() noexcept { return "UTF16"; }

    };

    inline constexpr const UTF16& utf16 = UTF16::instance;

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF16_H_
