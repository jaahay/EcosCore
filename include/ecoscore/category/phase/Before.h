// File: ecoscore/category/phase/Before.h
//// File: EcosCore/src/ecoscore/category/phase/Before.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_PHASE_BEFORE_H
#define ECOSCORE_ECOSCORE_CATEGORY_PHASE_BEFORE_H

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Before final : Member<Before, ecoscore::category::Phase> {
        friend Member<Before, ecoscore::category::Phase>;

    private:
        constexpr Before() noexcept = default;
        ~Before() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Before"; }
    };

} // namespace ecoscore::category::phase
#endif // ECOSCORE_ECOSCORE_CATEGORY_PHASE_BEFORE_H
