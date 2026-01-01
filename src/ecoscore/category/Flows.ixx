// /src/ecoscore/category/Flows.ixx
export module ecoscore.category.Flows;

import ecoscore.category.Category;

namespace ecoscore::category::flow {

    /**
     * @brief CRTP base for flow control categorys.
     *
     * @tparam Derived The derived flow category.
     */
    export template <typename Derived>
        struct Flow : Category<Derived> {
        protected:
            constexpr Flow() noexcept = default;
            constexpr ~Flow() noexcept = default;
    };

} // namespace ecoscore::category::flow
