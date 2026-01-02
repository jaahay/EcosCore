// File: ecoscore/category/Flow.h
#ifndef ECOSCORE_CATEGORY_FLOW_H_
#define ECOSCORE_CATEGORY_FLOW_H_

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief Flow category tag.
     */
    struct Flow : Category {
    protected:
        constexpr Flow() noexcept = default;

    public:
        Flow(const Flow&) = delete;
        Flow& operator=(const Flow&) = delete;
        ~Flow() noexcept = default;

        static constexpr std::string_view name() noexcept { return "Flow"; }
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_FLOW_H_
