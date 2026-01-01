//// File: EcosCore/src/ecoscore/category/flow/Continue.ixx
export module ecoscore.category.flow.Continue;

import std;

import ecoscore.category.Flow;
import ecoscore.category.Member;

namespace ecoscore::category::flow {

    export struct Continue final : Member<Continue, ecoscore::category::Flow> {
        friend Member<Continue, ecoscore::category::Flow>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Continue"; }
    };

} // namespace ecoscore::category::flow
