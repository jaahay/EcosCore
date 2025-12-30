// include/ecoscore/tag/Flows.h
#ifndef ECOSCORE_TAG_FLOWS_H
#define ECOSCORE_TAG_FLOWS_H

#include "ecoscore/tag/Category.h"

namespace ecoscore::tag {

    /**
     * @brief CRTP base for flow control tags.
     *
     * @tparam Derived The derived flow tag.
     */
    template <typename Derived>
    struct Flow : Category<Derived> {
    protected:
        constexpr Flow() noexcept = default;
    };

}  // namespace ecoscore::tag

#endif  // ECOSCORE_TAG_FLOWS_H
