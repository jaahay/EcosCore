// File: ecoscore/category/phase/Finalize.h
#ifndef ECOSCORE_CATEGORY_PHASE_FINALIZE_H_
#define ECOSCORE_CATEGORY_PHASE_FINALIZE_H_

/**
 * @file Finalize.h
 * @brief Concrete member representing the 'Finalize' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Finalize phase.
     */
    struct Finalize final : Member<Finalize, ecoscore::category::Phase> {
        friend Member<Finalize, ecoscore::category::Phase>;

    private:
        constexpr Finalize() noexcept = default;
        ~Finalize() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Finalize"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_FINALIZE_H_
