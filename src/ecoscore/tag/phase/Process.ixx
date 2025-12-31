// /src/ecoscore/tag/phase/Process.ixx
export module ecoscore.tag.phase.Process;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Process final : Phase, ecoscore::tag::Category<Process> {
        constexpr Process() noexcept = default;
        constexpr ~Process() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Process"; }
    };

}
