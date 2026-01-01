//// File: EcosCore/src/ecoscore/category/Outcome.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_OUTCOME_IXX__
#define __SRC_ECOSCORE_CATEGORY_OUTCOME_IXX__

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
#endif // __SRC_ECOSCORE_CATEGORY_OUTCOME_IXX__
