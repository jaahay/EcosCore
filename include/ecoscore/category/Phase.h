// File: ecoscore/category/Phase.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PASS_H_
#define ECOSCORE_CATEGORY_OUTCOME_PASS_H_

#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {
    struct Pass;  // Forward declaration
}

#include "ecoscore/category/Member.h"
#include <string_view>

namespace ecoscore::category::outcome {

    struct Pass final : ecoscore::category::Member<Pass, ecoscore::category::Outcome> {
        friend struct ecoscore::category::Member<Pass, ecoscore::category::Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Pass"; }
        static constexpr Pass create() { return Pass{}; }
    };

    inline constexpr const Pass& pass = Pass::instance;

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PASS_H_
