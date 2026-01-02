// File: ecoscore/category/outcome/Fail.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_FAIL_H_
#define ECOSCORE_CATEGORY_OUTCOME_FAIL_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

    /**
     * @brief Fail outcome member.
     */
    struct Fail final : Member<Fail, Outcome> {
        friend Member<Fail, Outcome>;

    private:
        constexpr Fail() noexcept = default;
        ~Fail() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Fail"; }

        static constexpr const Fail& instance() noexcept {
            static const Fail inst{};
            return inst;
        }
    };

    inline constexpr const Fail& fail = Fail::instance();

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_FAIL_H_
