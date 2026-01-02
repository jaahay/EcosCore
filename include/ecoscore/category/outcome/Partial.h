// File: ecoscore/category/outcome/Partial.h
#ifndef ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_
#define ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Outcome.h"

namespace ecoscore::category::outcome {

    /**
     * @brief Partial outcome member.
     */
    struct Partial final : Member<Partial, Outcome> {
        friend Member<Partial, Outcome>;

    private:
        constexpr Partial() noexcept = default;
        ~Partial() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Partial"; }

        static constexpr const Partial& instance() noexcept {
            static const Partial inst{};
            return inst;
        }
    };

    inline constexpr const Partial& partial = Partial::instance();

} // namespace ecoscore::category::outcome

#endif // ECOSCORE_CATEGORY_OUTCOME_PARTIAL_H_
