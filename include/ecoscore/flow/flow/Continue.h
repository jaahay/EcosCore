// File: ecoscore/flow/flow/Continue.h
#ifndef ECOSCORE_FLOW_FLOW_CONTINUE_H_
#define ECOSCORE_FLOW_FLOW_CONTINUE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/flow/Flow.h"

namespace ecoscore::flow::flow {

    struct Continue final : ecoscore::category::Member<Continue, Flow> {
        friend struct ecoscore::category::Member<Continue, Flow>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

        static constexpr Continue create() { return Continue{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Continue";
        }
    };

    inline constexpr const Continue& cnt = Continue::instance;

} // namespace ecoscore::flow::flow

#endif // ECOSCORE_FLOW_FLOW_CONTINUE_H_
