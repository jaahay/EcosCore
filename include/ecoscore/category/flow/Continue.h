// File: ecoscore/category/flow/Continue.h
#ifndef ECOSCORE_CATEGORY_FLOW_CONTINUE_H_
#define ECOSCORE_CATEGORY_FLOW_CONTINUE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Flow.h"

namespace ecoscore::category::flow {

    /**
     * @brief Continue flow member.
     */
    struct Continue final : Member<Continue, Flow> {
        friend Member<Continue, Flow>;

    private:
        constexpr Continue() noexcept = default;
        ~Continue() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Continue"; }

        static constexpr const Continue& instance() noexcept {
            static const Continue inst{};
            return inst;
        }
    };

    inline constexpr const Continue& cont = Continue::instance();

} // namespace ecoscore::category::flow

#endif // ECOSCORE_CATEGORY_FLOW_CONTINUE_H_
