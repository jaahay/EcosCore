// File: ecoscore/category/phase/Error.h
#ifndef ECOSCORE_CATEGORY_PHASE_ERROR_H_
#define ECOSCORE_CATEGORY_PHASE_ERROR_H_

#include "ecoscore/category/Member.h"
#include "ecoscore/category/Phase.h"

namespace ecoscore::category::phase {

    /**
     * @brief Error phase member.
     */
    struct Error final : Member<Error, Phase> {
        friend Member<Error, Phase>;

    private:
        constexpr Error() noexcept = default;
        ~Error() noexcept = default;

    public:
        static constexpr std::string_view name() noexcept { return "Error"; }

        static constexpr const Error& instance() noexcept {
            static const Error inst{};
            return inst;
        }
    };

    inline constexpr const Error& error = Error::instance();

} // namespace ecoscore::category::phase

#endif // ECOSCORE_CATEGORY_PHASE_ERROR_H_
