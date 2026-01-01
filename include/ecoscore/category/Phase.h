// File: ecoscore/category/Phase.h
//// File: EcosCore/src/ecoscore/category/Phase.ixx
#ifndef ECOSCORE_CATEGORY_PHASE_H
#define ECOSCORE_CATEGORY_PHASE_H

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
#endif // ECOSCORE_CATEGORY_PHASE_H
