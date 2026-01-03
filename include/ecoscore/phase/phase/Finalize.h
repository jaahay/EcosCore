// File: ecoscore/phase/phase/Finalize.h
#ifndef ECOSCORE_PHASE_PHASE_FINALIZE_H_
#define ECOSCORE_PHASE_PHASE_FINALIZE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Finalize final : ecoscore::category::Member<Finalize, Phase> {
        friend struct ecoscore::category::Member<Finalize, Phase>;

    private:
        constexpr Finalize() noexcept = default;
        ~Finalize() noexcept = default;

        static constexpr Finalize create() { return Finalize{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Finalize";
        }
    };

    inline constexpr const Finalize& finalize = Finalize::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_FINALIZE_H_
