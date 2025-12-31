// /src/ecoscore/state/outcome/Partial.ixx
export module ecoscore.state.outcome.Partial;

import ecoscore.state.Outcomes;
import ecoscore.state.Category;

namespace ecoscore::state::outcome {

    struct Partial final : Outcome<Partial> {
        constexpr Partial() noexcept = default;
        constexpr ~Partial() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Partial"; }
    };

}
