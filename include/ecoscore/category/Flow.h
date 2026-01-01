//// File: EcosCore/src/ecoscore/category/Flow.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_FLOW_IXX__
#define __SRC_ECOSCORE_CATEGORY_FLOW_IXX__

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
#endif // __SRC_ECOSCORE_CATEGORY_FLOW_IXX__
