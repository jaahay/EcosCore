// /src/ecoscore/tag/outcome/Partial.ixx
export module ecoscore.tag.outcome.Partial;

import ecoscore.tag.Outcomes;
import ecoscore.tag.Category;

namespace ecoscore::tag::outcome {

    struct Partial final : Outcome<Partial> {
        constexpr Partial() noexcept = default;
        constexpr ~Partial() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Partial"; }
    };

}
