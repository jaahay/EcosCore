// File: ecoscore/flow/flow/Stop.h
#ifndef ECOSCORE_FLOW_FLOW_STOP_H_
#define ECOSCORE_FLOW_FLOW_STOP_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/flow/Flow.h"

namespace ecoscore::flow::flow {

    struct Stop final : ecoscore::category::Member<Stop, Flow> {
        friend struct ecoscore::category::Member<Stop, Flow>;

    private:
        constexpr Stop() noexcept = default;
        ~Stop() noexcept = default;

        static constexpr Stop create() { return Stop{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Stop";
        }
    };

    inline constexpr const Stop& stop = Stop::instance;

} // namespace ecoscore::flow::flow

#endif // ECOSCORE_FLOW_FLOW_STOP_H_
