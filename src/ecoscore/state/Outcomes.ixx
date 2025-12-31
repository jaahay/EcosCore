// /src/ecoscore/state/Outcomes.ixx
export module ecoscore.state.Outcomes;

import ecoscore.state.Category;

namespace ecoscore::state::outcome {

    /**
     * @brief CRTP base for outcome states.
     *
     * @tparam Derived The derived outcome state.
     */
    export template <typename Derived>
        struct Outcome : Category<Derived> {
        protected:
            constexpr Outcome() noexcept = default;
            constexpr ~Outcome() noexcept = default;
    };

} // namespace ecoscore::state::outcome
