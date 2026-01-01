//// File: EcosCore/src/ecoscore/category/phase/After.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_AFTER_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_AFTER_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct After final : Member<After, ecoscore::category::Phase> {
        friend Member<After, ecoscore::category::Phase>;

    private:
        constexpr After() noexcept = default;
        ~After() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "After"; }
    };

} // namespace ecoscore::category::phase
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_AFTER_IXX__
