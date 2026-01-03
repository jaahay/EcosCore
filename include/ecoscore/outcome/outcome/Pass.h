// File: ecoscore/outcome/outcome/Pass.h
#ifndef ECOSCORE_OUTCOME_OUTCOME_PASS_H_
#define ECOSCORE_OUTCOME_OUTCOME_PASS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/outcome/Outcome.h"

namespace ecoscore::outcome::outcome {

    struct Pass final : ecoscore::category::Member<Pass, Outcome> {
        friend struct ecoscore::category::Member<Pass, Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

        static constexpr Pass create() { return Pass{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Pass";
        }
    };

    inline constexpr const Pass& pass = Pass::instance;

} // namespace ecoscore::outcome::outcome

#endif // ECOSCORE_OUTCOME_OUTCOME_PASS_H_
