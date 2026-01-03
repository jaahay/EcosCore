// File: ecoscore/phase/phase/Error.h
#ifndef ECOSCORE_PHASE_PHASE_ERROR_H_
#define ECOSCORE_PHASE_PHASE_ERROR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/phase/Phase.h"

namespace ecoscore::phase::phase {

    struct Error final : ecoscore::category::Member<Error, Phase> {
        friend struct ecoscore::category::Member<Error, Phase>;

    private:
        constexpr Error() noexcept = default;
        ~Error() noexcept = default;

        static constexpr Error create() { return Error{}; }
    public:
        static constexpr std::string_view name() noexcept {
            return "Error";
        }
    };

    inline constexpr const Error& error = Error::instance;

} // namespace ecoscore::phase::phase

#endif // ECOSCORE_PHASE_PHASE_ERROR_H_
