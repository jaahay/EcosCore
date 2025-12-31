// /src/ecoscore/state/phase/Finalize.ixx
export module ecoscore.state.phase.Finalize;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Finalize final : Phase<Finalize> {
        constexpr Finalize() noexcept = default;
        constexpr ~Finalize() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Finalize"; }
    };

}
