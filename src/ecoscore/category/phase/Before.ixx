// /src/ecoscore/category/phase/Before.ixx
export module ecoscore.category.phase.Before;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Before final : Phase<Before> {
        constexpr Before() noexcept = default;
        constexpr ~Before() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Before"; }
    };

}
