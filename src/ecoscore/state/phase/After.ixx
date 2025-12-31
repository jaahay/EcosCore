// /src/ecoscore/state/phase/After.ixx
export module ecoscore.state.phase.After;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct After final : Phase<After> {
        constexpr After() noexcept = default;
        constexpr ~After() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "After"; }
    };

}
