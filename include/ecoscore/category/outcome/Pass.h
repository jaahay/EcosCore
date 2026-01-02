// File: ecoscore/category/outcome/Pass.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PASS_H_
#define ECOSCORE_CATEGORY_OUTCOME_PASS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

    struct Pass final : ecoscore::category::Member<Pass, ecoscore::category::Outcome> {
        // Grant base class access to private constructor
        friend struct ecoscore::category::Member<Pass, ecoscore::category::Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

        static constexpr Pass create() { return Pass{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Pass";
        }
    };

    // Optional convenient alias
    inline constexpr const Pass& pass = Pass::instance;

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PASS_H_
