// include/ecoscore/language/lang/es.h
#ifndef ECOSCORE_LANGUAGE_LANG_ES_H
#define ECOSCORE_LANGUAGE_LANG_ES_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief Spanish language tag.
     */
    struct Es final : language::Language<Es> {
        friend tag::concepts::Category<Es>;

    protected:
        constexpr Es() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "Spanish";
        }

        static constexpr Es instance{};
    };

    /**
     * @brief Alias for the singleton instance of Spanish.
     */
    inline constexpr Es& Es = Es::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_ES_H
