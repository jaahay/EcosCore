// File: ecoscore/category/Phase.h
#ifndef ECOSCORE_CATEGORY_PHASE_H_
#define ECOSCORE_CATEGORY_PHASE_H_

#include "ecoscore/category/Category.h"

namespace ecoscore::category {

    /**
     * @brief Phase category tag.
     */
    struct Phase : Category {
    protected:
        constexpr Phase() noexcept = default;

    public:
        Phase(const Phase&) = delete;
        Phase& operator=(const Phase&) = delete;
        ~Phase() noexcept = default;

        static constexpr std::string_view name() noexcept { return "Phase"; }
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_PHASE_H_
