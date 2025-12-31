// /src/ecoscore/state/flow/Continue.ixx
export module ecoscore.state.flow.Continue;

import ecoscore.state.Flows;
import ecoscore.state.Category;

namespace ecoscore::state::flow {

    /**
     * @brief Concrete flow state representing "Continue".
     *
     * Inherits from Flow (abstract) and Category (leaf).
     */
    struct Continue final : Flow<Continue> {
        constexpr Continue() noexcept = default;
        constexpr ~Continue() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Continue";
        }
    };

}
