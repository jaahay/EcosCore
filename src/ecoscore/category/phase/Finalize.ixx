// /src/ecoscore/category/phase/Finalize.ixx
export module ecoscore.category.phase.Finalize;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Finalize final : Phase<Finalize> {
        constexpr Finalize() noexcept = default;
        constexpr ~Finalize() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Finalize"; }
    };

}
