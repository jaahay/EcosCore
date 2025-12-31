// /src/ecoscore/tag/phase/Start.ixx
export module ecoscore.tag.phase.Start;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Start final : Phase<Start> {
        constexpr Start() noexcept = default;
        constexpr ~Start() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Start"; }
    };

}
