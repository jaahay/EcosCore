// /src/ecoscore/language/Languages.ixx
export module ecoscore.language.Languages;

import std;

import ecoscore.state.Category;

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for language tags.
     *
     * @tparam Derived Concrete language tag.
     */
    export template <typename Derived>
        struct Language : ecoscore::state::Category<Derived> {
        protected:
            constexpr Language() noexcept = default;
            constexpr ~Language() noexcept = default;
    };

}
