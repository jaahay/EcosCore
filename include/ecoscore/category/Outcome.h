// File: ecoscore/category/Outcome.h
//// File: EcosCore/src/ecoscore/category/Outcome.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_H
#define ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_H

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief Marker base for outcome categories.
     */
struct Outcome : Category {
        Outcome() noexcept = default;
        Outcome(const Outcome&) = delete;
        Outcome& operator=(const Outcome&) = delete;
        Outcome(Outcome&&) = delete;
        Outcome& operator=(Outcome&&) = delete;
        ~Outcome() noexcept = default;
    };

} // namespace ecoscore::category
#endif // ECOSCORE_ECOSCORE_CATEGORY_OUTCOME_H
