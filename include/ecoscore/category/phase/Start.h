//// File: EcosCore/src/ecoscore/category/phase/Start.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_START_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_START_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Start final : Member<Start, ecoscore::category::Phase> {
        friend Member<Start, ecoscore::category::Phase>;

    private:
        constexpr Start() noexcept = default;
        ~Start() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Start"; }
    };

} // namespace ecoscore::category::phase
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_START_IXX__
