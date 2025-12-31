// /src/ecoscore/tag/phase/Finalize.ixx
export module ecoscore.tag.phase.Finalize;

import ecoscore.tag.Phases;
import ecoscore.tag.Category;

namespace ecoscore::tag::phase {

    struct Finalize final : Phase<Finalize> {
        constexpr Finalize() noexcept = default;
        constexpr ~Finalize() noexcept = default;

        [[nodiscard]] static constexpr std::string_view static_name() noexcept { return "Finalize"; }
    };

}
