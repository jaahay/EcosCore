// File: ecoscore/phase/phase/After.h
#ifndef ECOSCORE_PHASE_PHASE_AFTER_H_
#define ECOSCORE_PHASE_PHASE_AFTER_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct After final : ecoscore::category::Member<After, Phase> {
        friend struct ecoscore::category::Member<After, Phase>;

    private:
        constexpr After() noexcept = default;
        ~After() noexcept = default;

        static constexpr After create() { return After{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "After";
        }
    };

    inline constexpr const After& after = After::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_AFTER_H_
