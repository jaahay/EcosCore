// File: ecoscore/category/phase/After.h
#ifndef ECOSCORE_CATEGORY_PHASE_AFTER_H_
#define ECOSCORE_CATEGORY_PHASE_AFTER_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief After phase member.
     */
    struct After final : Member<After, Phase> {
        friend Member<After, Phase>;

    private:
        constexpr After() noexcept = default;
        ~After() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "After"; }

        static constexpr const After& instance() noexcept {
            static const After inst{};
            return inst;
        }
    };

    inline constexpr const After& after = After::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_AFTER_H_
