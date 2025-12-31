// /src/ecoscore/tag/flow/Continue.ixx
export module ecoscore.tag.flow.Continue;

import ecoscore.tag.Flows;
import ecoscore.tag.Category;

namespace ecoscore::tag::flow {

    /**
     * @brief Concrete flow tag representing "Continue".
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
