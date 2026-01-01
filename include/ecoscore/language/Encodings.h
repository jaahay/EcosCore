// File: ecoscore/language/Encodings.h
// /src/ecoscore/language/Encodings.ixx
#ifndef ECOSCORE_LANGUAGE_ENCODINGS_H
#define ECOSCORE_LANGUAGE_ENCODINGS_H

#include "std.h"

#include "ecoscore/language/TextRepresentations.h"

namespace ecoscore::language {

    /**
     * @brief Encoding category, subset of TextRepresentation.
     *
     * Represents a byte-level encoding scheme.
     */
template <typename Derived>
        struct Encoding : TextRepresentation<Derived> {
        protected:
            constexpr Encoding() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
} // namespace ecoscore::language
    };

}  // namespace ecoscore::language
#endif // ECOSCORE_LANGUAGE_ENCODINGS_H
