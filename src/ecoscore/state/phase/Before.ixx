// /src/ecoscore/state/phase/Before.ixx
export module ecoscore.state.phase.Before;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Before final : Phase<Before> {
        constexpr Before() noexcept = default;
        constexpr ~Before() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Before"; }
    };

}
