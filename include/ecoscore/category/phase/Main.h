// File: ecoscore/category/phase/Main.h
//// File: EcosCore/src/ecoscore/category/phase/Main.ixx
#ifndef ECOSCORE_CATEGORY_PHASE_MAIN_H
#define ECOSCORE_CATEGORY_PHASE_MAIN_H

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Main final : Member<Main, ecoscore::category::Phase> {
        friend Member<Main, ecoscore::category::Phase>;

    private:
        constexpr Main() noexcept = default;
        ~Main() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Main"; }
    };

} // namespace ecoscore::category::phase
#endif // ECOSCORE_CATEGORY_PHASE_MAIN_H
