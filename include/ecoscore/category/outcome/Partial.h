//// File: EcosCore/src/ecoscore/category/outcome/Partial.ixx
#ifndef __SRC_ECOSCORE_CATEGORY_OUTCOME_PARTIAL_IXX__
#define __SRC_ECOSCORE_CATEGORY_OUTCOME_PARTIAL_IXX__

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

struct Partial final : Member<Partial, ecoscore::category::Outcome> {
        friend Member<Partial, ecoscore::category::Outcome>;

    private:
        constexpr Partial() noexcept = default;
        ~Partial() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view name() noexcept { return "Partial"; }
    };

} // namespace ecoscore::category::outcome
#endif // __SRC_ECOSCORE_CATEGORY_OUTCOME_PARTIAL_IXX__
