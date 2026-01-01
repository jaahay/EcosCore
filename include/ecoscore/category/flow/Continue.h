//// File: EcosCore/src/ecoscore/category/flow/Continue.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_FLOW_CONTINUE_IXX__
#define __SRC_ECOSCORE_CATEGORY_FLOW_CONTINUE_IXX__

#include "std.h"

#include "ecoscore/category/Flow.h"
#include "ecoscore/category/Member.h"

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
#endif // __SRC_ECOSCORE_CATEGORY_FLOW_CONTINUE_IXX__
