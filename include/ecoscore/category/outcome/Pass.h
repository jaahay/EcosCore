// File: ecoscore/category/outcome/Pass.h
//// File: EcosCore/src/ecoscore/category/outcome/Pass.ixx
#ifndef ECOSCORE_CATEGORY_OUTCOME_PASS_H
#define ECOSCORE_CATEGORY_OUTCOME_PASS_H

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
#endif // ECOSCORE_CATEGORY_OUTCOME_PASS_H
