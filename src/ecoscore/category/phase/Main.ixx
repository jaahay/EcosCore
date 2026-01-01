// /src/ecoscore/category/phase/Main.ixx
export module ecoscore.category.phase.Main;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Main final : Phase<Main> {
        constexpr Main() noexcept = default;
        constexpr ~Main() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Main"; }
    };

}
