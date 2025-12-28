// examples/state/ExamplePriorities.h
#ifndef EXAMPLES_STATE_EXAMPLE_PRIORITIES_H
#define EXAMPLES_STATE_EXAMPLE_PRIORITIES_H

#include "EcosCore/state/PriorityOrdering.h"

namespace examples::state {

    struct LowerPriority : ecoscore::state::PriorityOrdering<LowerPriority> {
        static constexpr std::string_view static_name() noexcept { return "LowerPriority"; }
        static const LowerPriority& instance() {
            static LowerPriority inst;
            return inst;
        }
    };

    struct IndiscriminatePriority : ecoscore::state::PriorityOrdering<IndiscriminatePriority, ecoscore::meta::TypeList<LowerPriority>> {
        static constexpr std::string_view static_name() noexcept { return "IndiscriminatePriority"; }
        static const IndiscriminatePriority& instance() {
            static IndiscriminatePriority inst;
            return inst;
        }
    };

    struct HigherPriority : ecoscore::state::PriorityOrdering<HigherPriority, ecoscore::meta::TypeList<IndiscriminatePriority>> {
        static constexpr std::string_view static_name() noexcept { return "HigherPriority"; }
        static const HigherPriority& instance() {
            static HigherPriority inst;
            return inst;
        }
    };

    static_assert(ecoscore::state::CheckPriorityNoCycle<HigherPriority>, "Priority cycle detected");

} // namespace examples::state

#endif // EXAMPLES_STATE_EXAMPLE_PRIORITIES_H
