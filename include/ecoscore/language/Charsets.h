// include/ecoscore/language/Charsets.h
#ifndef ECOSCORE_LANGUAGE_CHARSETS_H
#define ECOSCORE_LANGUAGE_CHARSETS_H

#include "TextRepresentation.h"
#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Charset category, subset of TextRepresentation.
     *
     * Represents a character repertoire or script.
     */
    template <typename Derived>
    struct Charset : TextRepresentation<Derived> {
    protected:
        constexpr Charset() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return Derived::static_name();
        }
    };

}  // namespace ecoscore::language

#endif  // ECOSCORE_LANGUAGE_CHARSETS_H
