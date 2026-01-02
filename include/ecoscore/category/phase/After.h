// File: ecoscore/category/phase/After.h
//// File: EcosCore/src/ecoscore/category/phase/After.ixx
#ifndef ECOSCORE_CATEGORY_PHASE_AFTER_H
#define ECOSCORE_CATEGORY_PHASE_AFTER_H

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

#include <string_view>

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
#endif // ECOSCORE_CATEGORY_PHASE_AFTER_H
