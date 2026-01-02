// File: ecoscore/category/flow/Continue.h
#ifndef ECOSCORE_CATEGORY_FLOW_CONTINUE_H_
#define ECOSCORE_CATEGORY_FLOW_CONTINUE_H_

/**
 * @file Continue.h
 * @brief Concrete member representing the 'Continue' flow.
 */

#include "ecoscore/category/Flow.h"
#include "ecoscore/category/Member.h"

#include <string_view>

namespace ecoscore::category::flow {

    /**
     * @brief Concrete member for Continue flow.
     */
    struct Continue final : Member<Continue, ecoscore::category::Flow> {
        friend Member<Continue, ecoscore::category::Flow>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Continue"; }
    };

} // namespace ecoscore::category::flow

#endif // ECOSCORE_CATEGORY_FLOW_CONTINUE_H_
