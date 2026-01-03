// File: ecoscore/phase/phase/Main.h
#ifndef ECOSCORE_PHASE_PHASE_MAIN_H_
#define ECOSCORE_PHASE_PHASE_MAIN_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Main final : ecoscore::category::Member<Main, Phase> {
        friend struct ecoscore::category::Member<Main, Phase>;

    private:
        constexpr Main() noexcept = default;
        ~Main() noexcept = default;

        static constexpr Main create() { return Main{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Main";
        }
    };

    inline constexpr const Main& main = Main::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_MAIN_H_
