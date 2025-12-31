// /src/ecoscore/language/Languages.ixx
export module ecoscore.language.Languages;

import ecoscore.tag.concepts.Category;
import <string_view>;

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for language tags.
     *
     * @tparam Derived Concrete language tag.
     */
    export template <typename Derived>
        struct Language : concepts::Category<Derived> {
        protected:
            constexpr Language() noexcept = default;

        public:
            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }
    };

}
