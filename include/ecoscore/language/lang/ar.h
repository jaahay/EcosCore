// include/ecoscore/language/lang/ar.h
#ifndef ECOSCORE_LANGUAGE_LANG_AR_H
#define ECOSCORE_LANGUAGE_LANG_AR_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Arabic language tag.
     */
    struct Ar final : language::Language<Ar> {
        friend tag::concepts::Category<Ar>;

    protected:
        constexpr Ar() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Arabic";
        }

        static constexpr Ar instance{};
    };

    /**
     * @brief Alias for the singleton instance of Arabic.
     */
    inline constexpr Ar& Ar = Ar::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_AR_H
