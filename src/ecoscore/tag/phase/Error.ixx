// /src/ecoscore/tag/phase/Error.ixx
export module ecoscore.tag.phase.Error;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Error final : Phase<Error> {
        constexpr Error() noexcept = default;
        constexpr ~Error() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Error"; }
    };

}
