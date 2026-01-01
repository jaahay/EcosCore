// /src/ecoscore/category/phase/Error.ixx
export module ecoscore.category.phase.Error;

import ecoscore.category.Phases;
import ecoscore.category.Category;

namespace ecoscore::category::phase {

    struct Error final : Phase<Error> {
        constexpr Error() noexcept = default;
        constexpr ~Error() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Error"; }
    };

}
