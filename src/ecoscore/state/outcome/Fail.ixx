// /src/ecoscore/state/outcome/Fail.ixx
export module ecoscore.state.outcome.Fail;

import ecoscore.state.Outcomes;
import ecoscore.state.Category;

namespace ecoscore::state::outcome {

    struct Fail final : Outcome<Fail> {
        constexpr Fail() noexcept = default;
        constexpr ~Fail() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Fail"; }
    };

}
