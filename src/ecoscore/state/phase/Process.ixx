// /src/ecoscore/state/phase/Process.ixx
export module ecoscore.state.phase.Process;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Process final : Phase<Process> {
        constexpr Process() noexcept = default;
        constexpr ~Process() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Process"; }
    };

}
