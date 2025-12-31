// /src/ecoscore/language/Charsets.ixx
export module ecoscore.language.Charsets;

import ecoscore.language.TextRepresentations;
import <string_view>;

namespace ecoscore::language {

    /**
     * @brief Charset category, subset of TextRepresentation.
     *
     * Represents a character repertoire or script.
     */
    export template <typename Derived>
        struct Charset : TextRepresentation<Derived> {
        protected:
            constexpr Charset() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

}  // namespace ecoscore::language
