// File: ecoscore/category/Outcome.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_H_
#define ECOSCORE_CATEGORY_OUTCOME_H_

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::category {

    struct Outcome : Category {
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

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_OUTCOME_H_
