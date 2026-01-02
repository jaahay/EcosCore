// File: ecoscore/language/Translations.h
// /src/ecoscore/language/Translations.ixx
#ifndef ECOSCORE_LANGUAGE_TRANSLATIONS_H
#define ECOSCORE_LANGUAGE_TRANSLATIONS_H



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
} // namespace ecoscore::language::translation
    };
} // namespace ecoscore::language::translation
#endif // ECOSCORE_LANGUAGE_TRANSLATIONS_H
