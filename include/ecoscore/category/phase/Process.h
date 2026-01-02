// File: ecoscore/category/phase/Process.h
#ifndef ECOSCORE_CATEGORY_PHASE_PROCESS_H_
#define ECOSCORE_CATEGORY_PHASE_PROCESS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Process phase member.
     */
    struct Process final : Member<Process, Phase> {
        friend Member<Process, Phase>;

    private:
        constexpr Process() noexcept = default;
        ~Process() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Process"; }

        static constexpr const Process& instance() noexcept {
            static const Process inst{};
            return inst;
        }
    };

    inline constexpr const Process& process = Process::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_PROCESS_H_
