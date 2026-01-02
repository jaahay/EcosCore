// File: ecoscore/category/outcome/Pass.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PASS_H_
#define ECOSCORE_CATEGORY_OUTCOME_PASS_H_

/**
 * @file Pass.h
 * @brief Concrete member representing a passing outcome.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

#include <string_view>

namespace ecoscore::category::outcome {

    /**
     * @brief Concrete member for Pass outcome.
     */
    struct Pass final : Member<Pass, ecoscore::category::Outcome> {
        friend Member<Pass, ecoscore::category::Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Pass"; }
    };

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PASS_H_
