//// File: EcosCore/src/ecoscore/category/outcome/Fail.ixx
export module ecoscore.category.outcome.Fail;

import ecoscore.category.Member;
import ecoscore.category.Outcome;

namespace ecoscore::category::outcome {

    export struct Fail final : Member<Fail, ecoscore::category::Outcome> {
        friend Member<Fail, ecoscore::category::Outcome>;

    private:
        constexpr Fail() noexcept = default;
        ~Fail() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Fail"; }
    };

} // namespace ecoscore::category::outcome
