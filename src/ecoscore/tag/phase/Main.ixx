// /src/ecoscore/tag/phase/Main.ixx
export module ecoscore.tag.phase.Main;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Main final : Phase, ecoscore::tag::Category<Main> {
        constexpr Main() noexcept = default;
        constexpr ~Main() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Main"; }
    };

}
