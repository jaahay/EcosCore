// /src/ecoscore/state/phase/End.ixx
export module ecoscore.state.phase.End;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct End final : Phase<End> {
        constexpr End() noexcept = default;
        constexpr ~End() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "End"; }
    };

}
