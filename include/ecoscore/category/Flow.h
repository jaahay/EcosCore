// File: ecoscore/category/Flow.h
#ifndef ECOSCORE_CATEGORY_FLOW_H_
#define ECOSCORE_CATEGORY_FLOW_H_

/**
 * @file Flow.h
 * @brief Marker base for flow categories.
 *
 * @details
 * This struct acts as a tag base for all flow-related categories.
 * Copy and move operations are deleted to ensure immutability and uniqueness.
 */

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief Marker base for flow categories.
     */
    struct Flow : Category {
        Flow() noexcept = default;

        Flow(const Flow&) = delete;
        Flow& operator=(const Flow&) = delete;

        Flow(Flow&&) = delete;
        Flow& operator=(Flow&&) = delete;

        ~Flow() noexcept = default;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_FLOW_H_
