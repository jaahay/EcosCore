// File: ecoscore/language/TextRepresentation.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H_
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H_

#include "ecoscore/category/Category.h"

namespace ecoscore::language {

    /**
     * @brief Base category for all text representations.
     */
    struct TextRepresentation : ecoscore::category::Category {
    protected:
        constexpr TextRepresentation() noexcept = default;

    public:
        TextRepresentation(const TextRepresentation&) = delete;
        TextRepresentation& operator=(const TextRepresentation&) = delete;
        ~TextRepresentation() noexcept = default;

        static constexpr std::string_view name() noexcept { return "TextRepresentation"; }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H_
