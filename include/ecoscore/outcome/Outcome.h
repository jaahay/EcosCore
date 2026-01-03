// File: ecoscore/outcome/Outcome.h
#ifndef ECOSCORE_OUTCOME_OUTCOME_H_
#define ECOSCORE_OUTCOME_OUTCOME_H_

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::outcome {

    struct Outcome : ecoscore::category::Category {
    protected:
        constexpr Outcome() noexcept = default;

    public:
        Outcome(const Outcome&) = delete;
        Outcome& operator=(const Outcome&) = delete;
        ~Outcome() noexcept = default;

        static constexpr std::string_view name() noexcept {
            return "Outcome";
        }
    };

} // namespace ecoscore::outcome

#endif // ECOSCORE_OUTCOME_OUTCOME_H_
