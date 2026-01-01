//// File: EcosCore/src/ecoscore/category/phase/Process.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_PROCESS_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_PROCESS_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Process final : Member<Process, ecoscore::category::Phase> {
        friend Member<Process, ecoscore::category::Phase>;

    private:
        constexpr Process() noexcept = default;
        ~Process() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Process"; }
    };

} // namespace ecoscore::category::phase
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_PROCESS_IXX__
