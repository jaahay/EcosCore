// /src/ecoscore/category/flow/Stop.ixx
export module ecoscore.category.flow.Stop;

import ecoscore.category.Flows;
import ecoscore.category.Category;

namespace ecoscore::category::flow {

    /**
     * @brief Concrete flow category representing "Stop".
     *
     * Inherits from Flow (abstract) and Category (leaf).
     */
    struct Stop final : Flow<Stop> {
        constexpr Stop() noexcept = default;
        constexpr ~Stop() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Stop";
        }
    };

}
