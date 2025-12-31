// /src/ecoscore/tag/outcome/Fail.ixx
export module ecoscore.tag.outcome.Fail;

import ecoscore.tag.Outcomes;
import ecoscore.tag.Category;

namespace ecoscore::tag::outcome {

    struct Fail final : Outcome, ecoscore::tag::Category<Fail> {
        constexpr Fail() noexcept = default;
        constexpr ~Fail() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Fail"; }
    };

}
