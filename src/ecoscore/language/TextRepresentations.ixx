// /src/ecoscore/language/TextRepresentations.ixx
export module ecoscore.language.TextRepresentations;

import ecoscore.tag.concepts.Category;
import <string_view>;

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for all text representations.
     *
     * Represents any form of text encoding or character set.
     */
    export template <typename Derived>
        struct TextRepresentation : tag::concepts::Category<Derived> {
        protected:
            constexpr TextRepresentation() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

}  // namespace ecoscore::language
