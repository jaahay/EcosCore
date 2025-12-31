// /src/ecoscore/tag/flow/Stop.ixx
export module ecoscore.tag.flow.Stop;

import ecoscore.tag.Flows;
import ecoscore.tag.Category;

namespace ecoscore::tag::flow {

    /**
     * @brief Concrete flow tag representing "Stop".
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
