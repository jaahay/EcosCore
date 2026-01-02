// File: ecoscore/category/flow/Stop.h
#ifndef ECOSCORE_CATEGORY_FLOW_STOP_H_
#define ECOSCORE_CATEGORY_FLOW_STOP_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Flow.h"

namespace ecoscore::category::flow {

    /**
     * @brief Stop flow member.
     */
    struct Stop final : Member<Stop, Flow> {
        friend Member<Stop, Flow>;

    private:
        constexpr Stop() noexcept = default;
        ~Stop() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Stop"; }

        static constexpr const Stop& instance() noexcept {
            static const Stop inst{};
            return inst;
        }
    };

    inline constexpr const Stop& stop = Stop::instance();

} // namespace ecoscore::category::flow

#endif // ECOSCORE_CATEGORY_FLOW_STOP_H_
