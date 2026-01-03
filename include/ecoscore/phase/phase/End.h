// File: ecoscore/phase/phase/End.h
#ifndef ECOSCORE_PHASE_PHASE_END_H_
#define ECOSCORE_PHASE_PHASE_END_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct End final : ecoscore::category::Member<End, Phase> {
        friend struct ecoscore::category::Member<End, Phase>;

    private:
        constexpr End() noexcept = default;
        ~End() noexcept = default;

        static constexpr End create() { return End{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "End";
        }
    };

    inline constexpr const End& end = End::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_END_H_
