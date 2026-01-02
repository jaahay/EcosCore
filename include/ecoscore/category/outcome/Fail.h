// File: ecoscore/category/outcome/Fail.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_FAIL_H_
#define ECOSCORE_CATEGORY_OUTCOME_FAIL_H_

/**
 * @file Fail.h
 * @brief Concrete member representing a failing outcome.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

#include <string_view>

namespace ecoscore::category::outcome {

    /**
     * @brief Concrete member for Fail outcome.
     */
    struct Fail final : Member<Fail, ecoscore::category::Outcome> {
        friend Member<Fail, ecoscore::category::Outcome>;

    private:
        constexpr Fail() noexcept = default;
        ~Fail() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Fail"; }
    };

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_FAIL_H_
