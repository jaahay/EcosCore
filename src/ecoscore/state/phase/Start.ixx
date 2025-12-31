// /src/ecoscore/state/phase/Start.ixx
export module ecoscore.state.phase.Start;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Start final : Phase<Start> {
        constexpr Start() noexcept = default;
        constexpr ~Start() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Start"; }
    };

}
