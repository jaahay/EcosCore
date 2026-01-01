// /src/ecoscore/category/Outcomes.ixx
export module ecoscore.category.Outcomes;

import ecoscore.category.Category;

namespace ecoscore::category::outcome {

    /**
     * @brief CRTP base for outcome categorys.
     *
     * @tparam Derived The derived outcome category.
     */
    export struct Outcome : ecoscore::category::Category {
    };

    export template <typename Derived>
        struct OutcomeTemplate : ecoscore::category::TemplateCategory<Derived, Outcome> {
        protected:
            constexpr OutcomeTemplate() noexcept = default;
            constexpr ~OutcomeTemplate() noexcept = default;
    };

} // namespace ecoscore::category::outcome
