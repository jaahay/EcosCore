// File: ecoscore/category/phase/Start.h
//// File: EcosCore/src/ecoscore/category/phase/Start.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_PHASE_START_H
#define ECOSCORE_ECOSCORE_CATEGORY_PHASE_START_H

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
#endif // ECOSCORE_ECOSCORE_CATEGORY_PHASE_START_H
