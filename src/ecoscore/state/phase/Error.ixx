// /src/ecoscore/state/phase/Error.ixx
export module ecoscore.state.phase.Error;

import ecoscore.state.Phases;
import ecoscore.state.Category;

namespace ecoscore::state::phase {

    struct Error final : Phase<Error> {
        constexpr Error() noexcept = default;
        constexpr ~Error() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Error"; }
    };

}
