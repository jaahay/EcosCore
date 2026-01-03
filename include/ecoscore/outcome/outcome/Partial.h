// File: ecoscore/outcome/outcome/Partial.h
#ifndef ECOSCORE_OUTCOME_OUTCOME_PARTIAL_H_
#define ECOSCORE_OUTCOME_OUTCOME_PARTIAL_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/outcome/Outcome.h"

namespace ecoscore::outcome::outcome {

    struct Partial final : ecoscore::category::Member<Partial, Outcome> {
        friend struct ecoscore::category::Member<Partial, Outcome>;

    private:
        constexpr Partial() noexcept = default;
        ~Partial() noexcept = default;

        static constexpr Partial create() { return Partial{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Partial";
        }
    };

    inline constexpr const Partial& partial = Partial::instance;

} // namespace ecoscore::outcome::outcome

#endif // ECOSCORE_OUTCOME_OUTCOME_PARTIAL_H_
