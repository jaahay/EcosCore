// File: ecoscore/phase/phase/Start.h
#ifndef ECOSCORE_PHASE_PHASE_START_H_
#define ECOSCORE_PHASE_PHASE_START_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Start final : ecoscore::category::Member<Start, Phase> {
        friend struct ecoscore::category::Member<Start, Phase>;

    private:
        constexpr Start() noexcept = default;
        ~Start() noexcept = default;

        static constexpr Start create() { return Start{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Start";
        }
    };

    inline constexpr const Start& start = Start::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_START_H_
