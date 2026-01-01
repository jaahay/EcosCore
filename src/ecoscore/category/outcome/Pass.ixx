//// File: EcosCore/src/ecoscore/category/outcome/Pass.ixx
export module ecoscore.category.outcome.Pass;

import ecoscore.category.Member;
import ecoscore.category.Outcome;

namespace ecoscore::category::outcome {

    export struct Pass final : Member<Pass, ecoscore::category::Outcome> {
        friend Member<Pass, ecoscore::category::Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Pass"; }
    };

} // namespace ecoscore::category::outcome
