//// File: EcosCore/src/ecoscore/category/outcome/Pass.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_OUTCOME_PASS_IXX__
#define __SRC_ECOSCORE_CATEGORY_OUTCOME_PASS_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

struct Pass final : Member<Pass, ecoscore::category::Outcome> {
        friend Member<Pass, ecoscore::category::Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Pass"; }
    };

} // namespace ecoscore::category::outcome
#endif // __SRC_ECOSCORE_CATEGORY_OUTCOME_PASS_IXX__
