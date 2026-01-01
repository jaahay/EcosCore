// File: ecoscore/category/outcome/Fail.h
//// File: EcosCore/src/ecoscore/category/outcome/Fail.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_FAIL_H
#define ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_FAIL_H

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

struct Fail final : Member<Fail, ecoscore::category::Outcome> {
        friend Member<Fail, ecoscore::category::Outcome>;

    private:
        constexpr Fail() noexcept = default;
        ~Fail() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Fail"; }
    };

} // namespace ecoscore::category::outcome
#endif // ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_FAIL_H
