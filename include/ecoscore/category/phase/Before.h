// File: ecoscore/category/phase/Before.h
#ifndef ECOSCORE_CATEGORY_PHASE_BEFORE_H_
#define ECOSCORE_CATEGORY_PHASE_BEFORE_H_

/**
 * @file Before.h
 * @brief Concrete member representing the 'Before' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Before phase.
     */
    struct Before final : Member<Before, ecoscore::category::Phase> {
        friend Member<Before, ecoscore::category::Phase>;

    private:
        constexpr Before() noexcept = default;
        ~Before() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Before"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_BEFORE_H_
