// File: ecoscore/language/textrepresentation/UTF8.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief UTF8 character set.
     */
    struct UTF8 final : ecoscore::category::Member<UTF8, TextRepresentation> {
        friend ecoscore::category::Member<UTF8, TextRepresentation>;

    private:
        constexpr UTF8() noexcept = default;
        ~UTF8() noexcept = default;

        static constexpr UTF8 create() { return UTF8{}; }
    public:
        static constexpr std::string_view name() noexcept { return "UTF8"; }

    };

    inline constexpr const UTF8& utf8 = UTF8::instance;

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_UTF8_H_
