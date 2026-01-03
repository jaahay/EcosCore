// File: ecoscore/phase/phase/Before.h
#ifndef ECOSCORE_PHASE_PHASE_BEFORE_H_
#define ECOSCORE_PHASE_PHASE_BEFORE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Before final : ecoscore::category::Member<Before, Phase> {
        friend struct ecoscore::category::Member<Before, Phase>;

    private:
        constexpr Before() noexcept = default;
        ~Before() noexcept = default;

        static constexpr Before create() { return Before{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Before";
        }
    };

    inline constexpr const Before& before = Before::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_BEFORE_H_
