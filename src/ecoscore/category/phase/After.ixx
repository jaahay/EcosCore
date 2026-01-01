//// File: EcosCore/src/ecoscore/category/phase/After.ixx
export module ecoscore.category.phase.After;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct After final : Member<After, ecoscore::category::Phase> {
        friend Member<After, ecoscore::category::Phase>;

    private:
        constexpr After() noexcept = default;
        ~After() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "After"; }
    };

} // namespace ecoscore::category::phase
