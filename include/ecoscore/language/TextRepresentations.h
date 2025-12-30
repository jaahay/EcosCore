// include/ecoscore/language/TextRepresentations.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H

#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for all text representations.
     *
     * Represents any form of text encoding or character set.
     */
    template <typename Derived>
    struct TextRepresentation : tag::concepts::Category<Derived> {
    protected:
        constexpr TextRepresentation() noexcept = default;

    public:
        /**
         * @brief Returns the canonical internal name of the text representation.
         *
         * Not intended for user display.
         */
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return Derived::static_name();
        }
    };

}  // namespace ecoscore::language

#endif  // ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
