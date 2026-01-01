// /src/ecoscore/category/flow/Continue.ixx
export module ecoscore.category.flow.Continue;

import ecoscore.category.Flows;
import ecoscore.category.Category;

namespace ecoscore::category::flow {

    /**
     * @brief Concrete flow category representing "Continue".
     *
     * Inherits from Flow (abstract) and Category (leaf).
     */
    struct Continue final : Flow<Continue> {
        constexpr Continue() noexcept = default;
        constexpr ~Continue() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Continue";
        }
    };

}
