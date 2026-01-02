// File: ecoscore/category/phase/Start.h
#ifndef ECOSCORE_CATEGORY_PHASE_START_H_
#define ECOSCORE_CATEGORY_PHASE_START_H_

/**
 * @file Start.h
 * @brief Concrete member representing the 'Start' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Start phase.
     */
    struct Start final : Member<Start, ecoscore::category::Phase> {
        friend Member<Start, ecoscore::category::Phase>;

    private:
        constexpr Start() noexcept = default;
        ~Start() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Start"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_START_H_
