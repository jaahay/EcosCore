//// File: EcosCore/src/ecoscore/category/phase/Before.ixx
export module ecoscore.category.phase.Before;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct Before final : Member<Before, ecoscore::category::Phase> {
        friend Member<Before, ecoscore::category::Phase>;

    private:
        constexpr Before() noexcept = default;
        ~Before() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Before"; }
    };

} // namespace ecoscore::category::phase
