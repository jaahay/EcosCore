// /src/ecoscore/language/TextRepresentation.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_IXX__
#define __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_IXX__

#include "std.h"

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
            }
    };

}  // namespace ecoscore::language
#endif // __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATION_IXX__
