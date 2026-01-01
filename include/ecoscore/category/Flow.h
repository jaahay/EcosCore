// File: ecoscore/category/Flow.h
//// File: EcosCore/src/ecoscore/category/Flow.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_FLOW_H
#define ECOSCORE_ECOSCORE_CATEGORY_FLOW_H

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
#endif // ECOSCORE_ECOSCORE_CATEGORY_FLOW_H
