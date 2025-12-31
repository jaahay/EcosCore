// /src/ecoscore/language/TextRepresentations.ixx
export module ecoscore.language.TextRepresentations;

import std;

import ecoscore.state.Category;

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for all text representations.
     *
     * Represents any form of text encoding or character set.
     */
    export template <typename Derived>
        struct TextRepresentation : ecoscore::state::Category<Derived> {
        protected:
            constexpr TextRepresentation() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

}  // namespace ecoscore::language
