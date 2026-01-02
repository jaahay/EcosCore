// File: ecoscore/category/phase/Main.h
#ifndef ECOSCORE_CATEGORY_PHASE_MAIN_H_
#define ECOSCORE_CATEGORY_PHASE_MAIN_H_

/**
 * @file Main.h
 * @brief Concrete member representing the 'Main' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Main phase.
     */
    struct Main final : Member<Main, ecoscore::category::Phase> {
        friend Member<Main, ecoscore::category::Phase>;

    private:
        constexpr Main() noexcept = default;
        ~Main() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Main"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_MAIN_H_
