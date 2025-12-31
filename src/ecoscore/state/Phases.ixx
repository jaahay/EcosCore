// /src/ecoscore/state/Phases.ixx
export module ecoscore.state.Phases;

import ecoscore.state.Category;

namespace ecoscore::state::phase {

    /**
     * @brief CRTP base for phase states.
     *
     * @tparam Derived The derived phase state.
     */
    export template <typename Derived>
        struct Phase : Category<Derived> {
        protected:
            constexpr Phase() noexcept = default;
            constexpr ~Phase() noexcept = default;
    };

} // namespace ecoscore::state::phase
