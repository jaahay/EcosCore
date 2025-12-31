// /src/ecoscore/tag/phase/End.ixx
export module ecoscore.tag.phase.End;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct End final : Phase<End> {
        constexpr End() noexcept = default;
        constexpr ~End() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "End"; }
    };

}
