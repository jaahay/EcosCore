// File: ecoscore/category/Outcome.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_H_
#define ECOSCORE_CATEGORY_OUTCOME_H_

/**
 * @file Outcome.h
 * @brief Marker base for outcome categories.
 *
 * @details
 * This struct acts as a tag base for all outcome-related categories.
 * Copy and move operations are deleted to ensure immutability and uniqueness.
 */

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

#endif // ECOSCORE_CATEGORY_OUTCOME_H_
