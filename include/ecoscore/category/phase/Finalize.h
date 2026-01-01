// File: ecoscore/category/phase/Finalize.h
//// File: EcosCore/src/ecoscore/category/phase/Finalize.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_PHASE_FINALIZE_H
#define ECOSCORE_ECOSCORE_CATEGORY_PHASE_FINALIZE_H

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Finalize final : Member<Finalize, ecoscore::category::Phase> {
        friend Member<Finalize, ecoscore::category::Phase>;

    private:
        constexpr Finalize() noexcept = default;
        ~Finalize() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Finalize"; }
    };

} // namespace ecoscore::category::phase
#endif // ECOSCORE_ECOSCORE_CATEGORY_PHASE_FINALIZE_H
