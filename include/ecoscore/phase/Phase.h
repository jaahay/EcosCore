// File: ecoscore/phase/Phase.h
#ifndef ECOSCORE_PHASE_PHASE_H_
#define ECOSCORE_PHASE_PHASE_H_

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::phase {

    struct Phase : ecoscore::category::Category {
    protected:
        constexpr Phase() noexcept = default;

    public:
        Phase(const Phase&) = delete;
        Phase& operator=(const Phase&) = delete;
        ~Phase() noexcept = default;

        static constexpr std::string_view name() noexcept {
            return "Phase";
        }
    };

} // namespace ecoscore::phase

#endif // ECOSCORE_PHASE_PHASE_H_
