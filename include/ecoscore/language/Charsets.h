// /src/ecoscore/language/Charsets.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_CHARSETS_IXX__
#define __SRC_ECOSCORE_LANGUAGE_CHARSETS_IXX__

#include "std.h"

#include "ecoscore/language/TextRepresentations.h"

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
#endif // __SRC_ECOSCORE_LANGUAGE_CHARSETS_IXX__
