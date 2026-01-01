//// File: EcosCore/src/ecoscore/category/phase/Start.ixx
export module ecoscore.category.phase.Start;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Start final : Member<Start, ecoscore::category::Phase> {
        friend Member<Start, ecoscore::category::Phase>;

    private:
        constexpr Start() noexcept = default;
        ~Start() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Start"; }
    };

} // namespace ecoscore::category::phase
