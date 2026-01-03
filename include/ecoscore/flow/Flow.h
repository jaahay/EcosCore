// File: ecoscore/flow/Flow.h
#ifndef ECOSCORE_FLOW_FLOW_H_
#define ECOSCORE_FLOW_FLOW_H_

#include "ecoscore/category/Category.h"
#include <string_view>

namespace ecoscore::flow {

    struct Flow : ecoscore::category::Category {
    protected:
        constexpr Flow() noexcept = default;

    public:
        Flow(const Flow&) = delete;
        Flow& operator=(const Flow&) = delete;
        ~Flow() noexcept = default;

        static constexpr std::string_view name() noexcept {
            return "Flow";
        }
    };

} // namespace ecoscore::flow

#endif // ECOSCORE_FLOW_FLOW_H_
