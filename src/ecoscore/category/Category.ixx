// /src/ecoscore/category/Category.ixx
export module ecoscore.category.Category;

import std;

import ecoscore.category.detail;

namespace ecoscore::category {

    // Concept enforcing final & non-abstract or abstract & non-final,
    // but disables the check on MSVC due to compiler limitations.
    template <typename T>
    concept ValidCategoryDerived =
        ecoscore::category::detail::is_msvc || // Skip check on MSVC
        ((std::is_final_v<T> && !std::is_abstract_v<T>) ||
            (!std::is_final_v<T> && std::is_abstract_v<T>));

    /**
     * @brief CRTP base for all category categories.
     *
     * Provides a compile-time singleton instance and static_name().
     *
     * Supports both abstract intermediate categorys (non-final) and concrete leaf categorys (final).
     *
     * @tparam Derived The derived category type.
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

} // namespace ecoscore::category
