//// File: EcosCore/src/ecoscore/category/phase/End.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_END_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_END_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct End final : Member<End, ecoscore::category::Phase> {
        friend Member<End, ecoscore::category::Phase>;

    private:
        constexpr End() noexcept = default;
        ~End() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "End"; }
    };

} // namespace ecoscore::category::phase
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_END_IXX__
