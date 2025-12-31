// /src/ecoscore/state/phase/Main.ixx
export module ecoscore.state.phase.Main;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Main final : Phase<Main> {
        constexpr Main() noexcept = default;
        constexpr ~Main() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Main"; }
    };

}
