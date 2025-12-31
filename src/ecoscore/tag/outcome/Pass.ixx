// /src/ecoscore/tag/outcome/Pass.ixx
export module ecoscore.tag.outcome.Pass;

import ecoscore.tag.Outcomes;
import ecoscore.tag.Category;

namespace ecoscore::tag::outcome {

    struct Pass final : Outcome<Pass> {
        constexpr Pass() noexcept = default;
        constexpr ~Pass() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Pass"; }
    };

}
