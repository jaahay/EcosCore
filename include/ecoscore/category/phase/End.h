// File: ecoscore/category/phase/End.h
#ifndef ECOSCORE_CATEGORY_PHASE_END_H_
#define ECOSCORE_CATEGORY_PHASE_END_H_

/**
 * @file End.h
 * @brief Concrete member representing the 'End' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for End phase.
     */
    struct End final : Member<End, ecoscore::category::Phase> {
        friend Member<End, ecoscore::category::Phase>;

    private:
        constexpr End() noexcept = default;
        ~End() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "End"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_END_H_
