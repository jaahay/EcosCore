// File: ecoscore/category/flow/Continue.h
//// File: EcosCore/src/ecoscore/category/flow/Continue.ixx
#ifndef ECOSCORE_CATEGORY_FLOW_CONTINUE_H
#define ECOSCORE_CATEGORY_FLOW_CONTINUE_H

#include "ecoscore/category/Flow.h"
#include "ecoscore/category/Member.h"

#include <string_view>

namespace ecoscore::category::flow {

struct Continue final : Member<Continue, ecoscore::category::Flow> {
        friend Member<Continue, ecoscore::category::Flow>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Continue"; }
    };

} // namespace ecoscore::category::flow
#endif // ECOSCORE_CATEGORY_FLOW_CONTINUE_H
