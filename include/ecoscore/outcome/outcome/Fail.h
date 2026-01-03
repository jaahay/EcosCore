// File: ecoscore/outcome/outcome/Fail.h
#ifndef ECOSCORE_OUTCOME_OUTCOME_FAIL_H_
#define ECOSCORE_OUTCOME_OUTCOME_FAIL_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/outcome/Outcome.h"

namespace ecoscore::outcome::outcome {

    struct Fail final : ecoscore::category::Member<Fail, Outcome> {
        friend struct ecoscore::category::Member<Fail, Outcome>;

    private:
        constexpr Fail() noexcept = default;
        ~Fail() noexcept = default;

        static constexpr Fail create() { return Fail{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Fail";
        }
    };

    inline constexpr const Fail& fail = Fail::instance;

} // namespace ecoscore::outcome::outcome

#endif // ECOSCORE_OUTCOME_OUTCOME_FAIL_H_
