// /src/ecoscore/tag/phase/Before.ixx
export module ecoscore.tag.phase.Before;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Before final : Phase, ecoscore::tag::Category<Before> {
        constexpr Before() noexcept = default;
        constexpr ~Before() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Before"; }
    };

}
