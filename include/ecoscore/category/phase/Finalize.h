// File: ecoscore/category/phase/Finalize.h
#ifndef ECOSCORE_CATEGORY_PHASE_FINALIZE_H_
#define ECOSCORE_CATEGORY_PHASE_FINALIZE_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Finalize phase member.
     */
    struct Finalize final : Member<Finalize, Phase> {
        friend Member<Finalize, Phase>;

    private:
        constexpr Finalize() noexcept = default;
        ~Finalize() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Finalize"; }

        static constexpr const Finalize& instance() noexcept {
            static const Finalize inst{};
            return inst;
        }
    };

    inline constexpr const Finalize& finalize = Finalize::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_FINALIZE_H_
