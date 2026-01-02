// File: ecoscore/category/phase/After.h
#ifndef ECOSCORE_CATEGORY_PHASE_AFTER_H_
#define ECOSCORE_CATEGORY_PHASE_AFTER_H_

/**
 * @file After.h
 * @brief Concrete member representing the 'After' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for After phase.
     */
    struct After final : Member<After, ecoscore::category::Phase> {
        friend Member<After, ecoscore::category::Phase>;

    private:
        constexpr After() noexcept = default;
        ~After() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "After"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_AFTER_H_
