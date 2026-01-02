// File: ecoscore/category/phase/Start.h
#ifndef ECOSCORE_CATEGORY_PHASE_START_H_
#define ECOSCORE_CATEGORY_PHASE_START_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Start phase member.
     */
    struct Start final : Member<Start, Phase> {
        friend Member<Start, Phase>;

    private:
        constexpr Start() noexcept = default;
        ~Start() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Start"; }

        static constexpr const Start& instance() noexcept {
            static const Start inst{};
            return inst;
        }
    };

    inline constexpr const Start& start = Start::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_START_H_
