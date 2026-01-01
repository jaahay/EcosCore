// /src/ecoscore/category/outcome/Fail.ixx
export module ecoscore.category.outcome.Fail;

import ecoscore.category.Outcomes;
import ecoscore.category.Category;

namespace ecoscore::category::outcome {

    struct Fail final : OutcomeTemplate<Fail> {
        constexpr Fail() noexcept = default;
        constexpr ~Fail() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Fail"; }
    };

}
