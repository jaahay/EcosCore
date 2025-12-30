// tag/flow/Continue.h
#ifndef ECOSCORE_TAG_FLOW_CONTINUE_H
#define ECOSCORE_TAG_FLOW_CONTINUE_H

#include "ecoscore/tag/Flows.h"
#include <string_view>

namespace ecoscore::tag::flow {

    /**
     * @brief Flow control tag indicating continuation.
     */
    struct Continue final : tag::Flow<Continue> {
        friend tag::Category<Continue>;

    protected:
        constexpr Continue() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Continue";
        }
    };

}  // namespace ecoscore::tag::flow

#endif  // ECOSCORE_TAG_FLOW_CONTINUE_H
