// /src/ecoscore/state/flow/Stop.ixx
export module ecoscore.state.flow.Stop;

import ecoscore.state.Flows;
import ecoscore.state.Category;

namespace ecoscore::state::flow {

    /**
     * @brief Concrete flow state representing "Stop".
     *
     * Inherits from Flow (abstract) and Category (leaf).
     */
    struct Stop final : Flow<Stop> {
        constexpr Stop() noexcept = default;
        constexpr ~Stop() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Stop";
        }
    };

}
