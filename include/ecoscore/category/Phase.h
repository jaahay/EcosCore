//// File: EcosCore/src/ecoscore/category/Phase.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_IXX__

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
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_IXX__
