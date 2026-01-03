// File: ecoscore/language/textrepresentation/ISO_8859_1.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/language/TextRepresentation.h"

namespace ecoscore::language::textrepresentation {

    /**
     * @brief ISO_8859_1 character set.
     */
    struct ISO_8859_1 final : ecoscore::category::Member<ISO_8859_1, TextRepresentation> {
        friend ecoscore::category::Member<ISO_8859_1, TextRepresentation>;

    private:
        constexpr ISO_8859_1() noexcept = default;
        ~ISO_8859_1() noexcept = default;

        static constexpr ISO_8859_1 create() { return ISO_8859_1{}; }
    public:
        static constexpr std::string_view name() noexcept { return "ISO_8859_1"; }

    };

    inline constexpr const ISO_8859_1& iso_8859_1 = ISO_8859_1::instance;

} // namespace ecoscore::language::textrepresentation

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_ISO_8859_1_H_
