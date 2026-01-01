//// File: EcosCore/src/ecoscore/category/phase/Error.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_PHASE_ERROR_IXX__
#define __SRC_ECOSCORE_CATEGORY_PHASE_ERROR_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

struct Error final : Member<Error, ecoscore::category::Phase> {
        friend Member<Error, ecoscore::category::Phase>;

    private:
        constexpr Error() noexcept = default;
        ~Error() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Error"; }
    };

} // namespace ecoscore::category::phase
#endif // __SRC_ECOSCORE_CATEGORY_PHASE_ERROR_IXX__
