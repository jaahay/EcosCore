// File: ecoscore/category/phase/Error.h
#ifndef ECOSCORE_CATEGORY_PHASE_ERROR_H_
#define ECOSCORE_CATEGORY_PHASE_ERROR_H_

/**
 * @file Error.h
 * @brief Concrete member representing the 'Error' phase.
 */

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

namespace ecoscore::category::phase {

    /**
     * @brief Concrete member for Error phase.
     */
    struct Error final : Member<Error, ecoscore::category::Phase> {
        friend Member<Error, ecoscore::category::Phase>;

    private:
        constexpr Error() noexcept = default;
        ~Error() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Error"; }
    };

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_ERROR_H_
