// /src/ecoscore/category/outcome/Pass.ixx
export module ecoscore.category.outcome.Pass;

import ecoscore.category.Outcomes;
import ecoscore.category.Category;

namespace ecoscore::category::outcome {

    struct Pass final : OutcomeTemplate<Pass> {
        constexpr Pass() noexcept = default;
        constexpr ~Pass() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Pass"; }
    };

}
