// /src/ecoscore/category/Phases.ixx
export module ecoscore.category.Phases;

import ecoscore.category.Category;

namespace ecoscore::category::phase {

    /**
     * @brief CRTP base for phase categorys.
     *
     * @tparam Derived The derived phase category.
     */
    export template <typename Derived>
        struct Phase : Category<Derived> {
        protected:
            constexpr Phase() noexcept = default;
            constexpr ~Phase() noexcept = default;
    };

} // namespace ecoscore::category::phase
