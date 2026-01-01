//// File: EcosCore/src/ecoscore/category/phase/Process.ixx
export module ecoscore.category.phase.Process;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Process final : Member<Process, ecoscore::category::Phase> {
        friend Member<Process, ecoscore::category::Phase>;

    private:
        constexpr Process() noexcept = default;
        ~Process() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Process"; }
    };

} // namespace ecoscore::category::phase
