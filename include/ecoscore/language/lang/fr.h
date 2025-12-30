// include/ecoscore/language/lang/fr.h
#ifndef ECOSCORE_LANGUAGE_LANG_FR_H
#define ECOSCORE_LANGUAGE_LANG_FR_H

#include "ecoscore/language/Languages.h"
#include "ecoscore/tag/Concepts.h"
#include <string_view>

namespace ecoscore::language::lang {

    /**
     * @brief French language tag.
     */
    struct Fr final : language::Language<Fr> {
        friend tag::concepts::Category<Fr>;

    protected:
        constexpr Fr() noexcept = default;

    public:
        [[nodiscard]] static constexpr std::string_view static_name() noexcept {
            return "French";
        }

        static constexpr Fr instance{};
    };

    /**
     * @brief Alias for the singleton instance of French.
     */
    inline constexpr Fr& Fr = Fr::instance;

}  // namespace ecoscore::language::lang

#endif  // ECOSCORE_LANGUAGE_LANG_FR_H
