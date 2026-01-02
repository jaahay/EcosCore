// File: ecoscore/category/outcome/Partial.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_
#define ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_

/**
 * @file Partial.h
 * @brief Concrete member representing a partial outcome.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

#include <string_view>

namespace ecoscore::category::outcome {

    /**
     * @brief Concrete member for Partial outcome.
     */
    struct Partial final : Member<Partial, ecoscore::category::Outcome> {
        friend Member<Partial, ecoscore::category::Outcome>;

    private:
        constexpr Partial() noexcept = default;
        ~Partial() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Partial"; }
    };

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_
