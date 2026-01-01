//// File: EcosCore/src/ecoscore/category/phase/End.ixx
export module ecoscore.category.phase.End;

import ecoscore.category.Member;
import ecoscore.category.Phase;

namespace ecoscore::category::phase {

    export struct End final : Member<End, ecoscore::category::Phase> {
        friend Member<End, ecoscore::category::Phase>;

    private:
        constexpr End() noexcept = default;
        ~End() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "End"; }
    };

} // namespace ecoscore::category::phase
