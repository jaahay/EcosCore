//// File: EcosCore/src/ecoscore/category/outcome/Partial.ixx
export module ecoscore.category.outcome.Partial;

import ecoscore.category.Member;
import ecoscore.category.Outcome;

namespace ecoscore::category::outcome {

    export struct Partial final : Member<Partial, ecoscore::category::Outcome> {
        friend Member<Partial, ecoscore::category::Outcome>;

    private:
        constexpr Partial() noexcept = default;
        ~Partial() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Partial"; }
    };

} // namespace ecoscore::category::outcome
