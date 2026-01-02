// File: ecoscore/category/phase/Before.h
#ifndef ECOSCORE_CATEGORY_PHASE_BEFORE_H_
#define ECOSCORE_CATEGORY_PHASE_BEFORE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Before phase member.
     */
    struct Before final : Member<Before, Phase> {
        friend Member<Before, Phase>;

    private:
        constexpr Before() noexcept = default;
        ~Before() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Before"; }

        static constexpr const Before& instance() noexcept {
            static const Before inst{};
            return inst;
        }
    };

    inline constexpr const Before& before = Before::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_BEFORE_H_
