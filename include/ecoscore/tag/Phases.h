// include/ecoscore/tag/Phases.h
#ifndef ECOSCORE_TAG_PHASES_H
#define ECOSCORE_TAG_PHASES_H

#include "ecoscore/tag/Category.h"

namespace ecoscore::tag {

    /**
     * @brief CRTP base for phase tags.
     *
     * @tparam Derived The derived phase tag.
     */
    template <typename Derived>
    struct Phase : Category<Derived> {
    protected:
        constexpr Phase() noexcept = default;
    };

}  // namespace ecoscore::tag

#endif  // ECOSCORE_TAG_PHASES_H
