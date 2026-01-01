// /src/ecoscore/category/phase/After.ixx
export module ecoscore.category.phase.After;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct After final : Phase<After> {
        constexpr After() noexcept = default;
        constexpr ~After() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "After"; }
    };

}
