// /src/ecoscore/tag/phase/After.ixx
export module ecoscore.tag.phase.After;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct After final : Phase, ecoscore::tag::Category<After> {
        constexpr After() noexcept = default;
        constexpr ~After() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "After"; }
    };

}
