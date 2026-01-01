// /src/ecoscore/category/phase/Start.ixx
export module ecoscore.category.phase.Start;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Start final : Phase<Start> {
        constexpr Start() noexcept = default;
        constexpr ~Start() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Start"; }
    };

}
