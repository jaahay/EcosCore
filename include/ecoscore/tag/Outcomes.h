// include/ecoscore/tag/Outcomes.h
#ifndef ECOSCORE_TAG_OUTCOMES_H
#define ECOSCORE_TAG_OUTCOMES_H

#include "ecoscore/tag/Category.h"

namespace ecoscore::tag {

    /**
     * @brief CRTP base for outcome tags.
     *
     * @tparam Derived The derived outcome tag.
     */
    template <typename Derived>
    struct Outcome : Category<Derived> {
    protected:
        constexpr Outcome() noexcept = default;
    };

}  // namespace ecoscore::tag

#endif  // ECOSCORE_TAG_OUTCOMES_H
