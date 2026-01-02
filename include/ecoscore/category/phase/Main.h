// File: ecoscore/category/phase/Main.h
#ifndef ECOSCORE_CATEGORY_PHASE_MAIN_H_
#define ECOSCORE_CATEGORY_PHASE_MAIN_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Main phase member.
     */
    struct Main final : Member<Main, Phase> {
        friend Member<Main, Phase>;

    private:
        constexpr Main() noexcept = default;
        ~Main() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Main"; }

        static constexpr const Main& instance() noexcept {
            static const Main inst{};
            return inst;
        }
    };

    inline constexpr const Main& main = Main::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_MAIN_H_
