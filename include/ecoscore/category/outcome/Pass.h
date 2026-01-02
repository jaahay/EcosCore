// File: ecoscore/category/outcome/Pass.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PASS_H_
#define ECOSCORE_CATEGORY_OUTCOME_PASS_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

    /**
     * @brief Pass outcome member.
     */
    struct Pass final : Member<Pass, Outcome> {
        friend Member<Pass, Outcome>;

    private:
        constexpr Pass() noexcept = default;
        ~Pass() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Pass"; }

        static constexpr const Pass& instance() noexcept {
            static const Pass inst{};
            return inst;
        }
    };

    inline constexpr const Pass& pass = Pass::instance();

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PASS_H_
