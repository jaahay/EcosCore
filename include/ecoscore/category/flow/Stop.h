//// File: EcosCore/src/ecoscore/category/flow/Stop.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_FLOW_STOP_IXX__
#define __SRC_ECOSCORE_CATEGORY_FLOW_STOP_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Flow.h"

namespace ecoscore::category::flow {

struct Stop final : Member<Stop, ecoscore::category::Flow> {
        friend Member<Stop, ecoscore::category::Flow>;

    private:
        constexpr Stop() noexcept = default;
        ~Stop() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Stop"; }
    };

} // namespace ecoscore::category::flow
#endif // __SRC_ECOSCORE_CATEGORY_FLOW_STOP_IXX__
