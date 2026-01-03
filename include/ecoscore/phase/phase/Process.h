// File: ecoscore/phase/phase/Process.h
#ifndef ECOSCORE_PHASE_PHASE_PROCESS_H_
#define ECOSCORE_PHASE_PHASE_PROCESS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Process final : ecoscore::category::Member<Process, Phase> {
        friend struct ecoscore::category::Member<Process, Phase>;

    private:
        constexpr Process() noexcept = default;
        ~Process() noexcept = default;

        static constexpr Process create() { return Process{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Process";
        }
    };

    inline constexpr const Process& process = Process::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_PROCESS_H_
