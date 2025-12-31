// /src/ecoscore/tag/Category.ixx
export module ecoscore.tag.Category;

import ecoscore.tag.detail;

import <string_view>;
import <type_traits>;

namespace ecoscore::tag {

    // Concept enforcing final & non-abstract or abstract & non-final,
    // but disables the check on MSVC due to compiler limitations.
    template <typename T>
    concept ValidCategoryDerived =
        ecoscore::tag::detail::is_msvc || // Skip check on MSVC
        ((std::is_final_v<T> && !std::is_abstract_v<T>) ||
            (!std::is_final_v<T> && std::is_abstract_v<T>));

    /**
     * @brief CRTP base for all tag categories.
     *
     * Provides a compile-time singleton instance and static_name().
     *
     * Supports both abstract intermediate tags (non-final) and concrete leaf tags (final).
     *
     * @note The static_name() method returns a canonical, internal identifier string.
     *       This string is a stable, machine-readable key used for compile-time dispatch,
     *       serialization, and metadata lookup.
     *
     *       It is NOT intended for display to end users and should never be localized.
     *       User-facing names and descriptions must be provided separately via localization data.
     *
     * @tparam Derived The derived tag type.
     */
    export template <ValidCategoryDerived Derived>
        struct Category {
        protected:
            constexpr Category() noexcept = default;
            constexpr ~Category() noexcept = default;

        public:
            Category(const Category&) = delete;
            Category& operator=(const Category&) = delete;

            [[nodiscard]] static constexpr const Derived& instance() noexcept {
                static constexpr Derived inst{};
                return inst;
            }

            [[nodiscard]] static constexpr std::string_view static_name() noexcept {
                return Derived::static_name();
            }

    };

} // namespace ecoscore::tag
