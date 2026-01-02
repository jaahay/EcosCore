// File: ecoscore/category/Phase.h
#ifndef ECOSCORE_CATEGORY_PHASE_H_
#define ECOSCORE_CATEGORY_PHASE_H_

/**
 * @file Phase.h
 * @brief Marker base for phase categories.
 *
 * @details
 * This struct acts as a tag base for all phase-related categories.
 * Copy and move operations are deleted to ensure immutability and uniqueness.
 */

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief Marker base for phase categories.
     */
    struct Phase : Category {
        Phase() noexcept = default;

        Phase(const Phase&) = delete;
        Phase& operator=(const Phase&) = delete;

        Phase(Phase&&) = delete;
        Phase& operator=(Phase&&) = delete;

        ~Phase() noexcept = default;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_PHASE_H_
