// /src/ecoscore/state/outcome/Pass.ixx
export module ecoscore.state.outcome.Pass;

import ecoscore.state.Outcomes;
import ecoscore.state.Category;

namespace ecoscore::state::outcome {

    struct Pass final : Outcome<Pass> {
        constexpr Pass() noexcept = default;
        constexpr ~Pass() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Pass"; }
    };

}
