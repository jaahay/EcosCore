// /src/ecoscore/category/phase/End.ixx
export module ecoscore.category.phase.End;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct End final : Phase<End> {
        constexpr End() noexcept = default;
        constexpr ~End() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "End"; }
    };

}
