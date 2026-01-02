// File: ecoscore/category/flow/Stop.h
#ifndef ECOSCORE_CATEGORY_FLOW_STOP_H_
#define ECOSCORE_CATEGORY_FLOW_STOP_H_

/**
 * @file Stop.h
 * @brief Concrete member representing the 'Stop' flow.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Flow.h"

#include <string_view>

namespace ecoscore::category::flow {

    /**
     * @brief Concrete member for Stop flow.
     */
    struct Stop final : Member<Stop, ecoscore::category::Flow> {
        friend Member<Stop, ecoscore::category::Flow>;

    private:
        constexpr Stop() noexcept = default;
        ~Stop() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Stop"; }
    };

} // namespace ecoscore::category::flow

#endif // ECOSCORE_CATEGORY_FLOW_STOP_H_
