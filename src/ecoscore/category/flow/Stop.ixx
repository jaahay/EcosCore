//// File: EcosCore/src/ecoscore/category/flow/Stop.ixx
export module ecoscore.category.flow.Stop;

import ecoscore.category.Member;
import ecoscore.category.Flow;

namespace ecoscore::category::flow {

    export struct Stop final : Member<Stop, ecoscore::category::Flow> {
        friend Member<Stop, ecoscore::category::Flow>;

    private:
        constexpr Stop() noexcept = default;
        ~Stop() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Stop"; }
    };

} // namespace ecoscore::category::flow
