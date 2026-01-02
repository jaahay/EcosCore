// File: ecoscore/language/TextRepresentation.h
// /src/ecoscore/language/TextRepresentation.ixx
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H



#include "ecoscore/category/Category.h"

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for all text representations.
     *
     * Represents any form of text encoding or character set.
     */
template <typename Derived>
        struct TextRepresentation : ecoscore::category::Category<Derived> {
        protected:
            constexpr TextRepresentation() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
} // namespace ecoscore::language
    };

}  // namespace ecoscore::language
#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATION_H
