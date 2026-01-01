// /src/ecoscore/category/outcome/Partial.ixx
export module ecoscore.category.outcome.Partial;

import ecoscore.category.Outcomes;
import ecoscore.category.Category;

namespace ecoscore::category::outcome {

    struct Partial final : OutcomeTemplate<Partial> {
        constexpr Partial() noexcept = default;
        constexpr ~Partial() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Partial"; }
    };

}
