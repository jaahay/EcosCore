// include/ecoscore/language/Languages.h
#ifndef ECOSCORE_LANGUAGE_LANGUAGES_H
#define ECOSCORE_LANGUAGE_LANGUAGES_H

#include "ecoscore/tag/concepts/Category.h"
#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Base CRTP template for language tags.
     *
     * @tparam Derived Concrete language tag.
     *
     * @note static_name() returns internal canonical name (not user-facing).
     */
    template <typename Derived>
    struct Language : concepts::Category<Derived> {
    protected:
        constexpr Language() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return Derived::static_name();
        }
    };

}  // namespace ecoscore::language

#endif  // ECOSCORE_LANGUAGE_LANGUAGES_H
