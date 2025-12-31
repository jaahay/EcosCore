// /src/ecoscore/state/Flows.ixx
export module ecoscore.state.Flows;

import ecoscore.state.Category;

namespace ecoscore::state {

    /**
     * @brief CRTP base for flow control states.
     *
     * @tparam Derived The derived flow state.
     */
    export template <typename Derived>
        struct Flow : Category<Derived> {
        protected:
            constexpr Flow() noexcept = default;
            constexpr ~Flow() noexcept = default;
    };

} // namespace ecoscore::state
