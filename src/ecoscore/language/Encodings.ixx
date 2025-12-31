// /src/ecoscore/language/Encodings.ixx
export module ecoscore.language.Encodings;

import std;

import ecoscore.language.TextRepresentations;

namespace ecoscore::language {

    /**
     * @brief Encoding category, subset of TextRepresentation.
     *
     * Represents a byte-level encoding scheme.
     */
    export template <typename Derived>
        struct Encoding : TextRepresentation<Derived> {
        protected:
            constexpr Encoding() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

}  // namespace ecoscore::language
