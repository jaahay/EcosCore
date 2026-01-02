// File: ecoscore/category/phase/End.h
#ifndef ECOSCORE_CATEGORY_PHASE_END_H_
#define ECOSCORE_CATEGORY_PHASE_END_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief End phase member.
     */
    struct End final : Member<End, Phase> {
        friend Member<End, Phase>;

    private:
        constexpr End() noexcept = default;
        ~End() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "End"; }

        static constexpr const End& instance() noexcept {
            static const End inst{};
            return inst;
        }
    };

    inline constexpr const End& end = End::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_END_H_
