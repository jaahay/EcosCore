// File: ecoscore/category/flow/Stop.h
//// File: EcosCore/src/ecoscore/category/flow/Stop.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_FLOW_STOP_H
#define ECOSCORE_ECOSCORE_CATEGORY_FLOW_STOP_H

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
#endif // ECOSCORE_ECOSCORE_CATEGORY_FLOW_STOP_H
