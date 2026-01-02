// File: ecoscore/category/phase/Process.h
#ifndef ECOSCORE_CATEGORY_PHASE_PROCESS_H_
#define ECOSCORE_CATEGORY_PHASE_PROCESS_H_

/**
 * @file Process.h
 * @brief Concrete member representing the 'Process' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Process phase.
     */
    struct Process final : Member<Process, ecoscore::category::Phase> {
        friend Member<Process, ecoscore::category::Phase>;

    private:
        constexpr Process() noexcept = default;
        ~Process() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Process"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_PROCESS_H_
