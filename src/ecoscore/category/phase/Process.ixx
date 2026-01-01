// /src/ecoscore/category/phase/Process.ixx
export module ecoscore.category.phase.Process;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Process final : Phase<Process> {
        constexpr Process() noexcept = default;
        constexpr ~Process() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Process"; }
    };

}
