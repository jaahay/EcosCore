// /src/ecoscore/language/Translations.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_TRANSLATIONS_IXX__
#define __SRC_ECOSCORE_LANGUAGE_TRANSLATIONS_IXX__

#include "std.h"

// Export concrete translation modules
#include "ecoscore/language/translations/en.h"
// export import ecoscore.language.translations.fr;
// export import ecoscore.language.translations.de;
// ... add other languages as you implement them

namespace ecoscore::language::translation {

    /**
     * @brief Umbrella domain module for all language translations.
     */
    struct TranslationsDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.language.translation";
        }
    };
} // namespace ecoscore::language::translation
#endif // __SRC_ECOSCORE_LANGUAGE_TRANSLATIONS_IXX__
