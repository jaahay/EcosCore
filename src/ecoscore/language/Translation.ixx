// /src/ecoscore/language/Translation.ixx
export module ecoscore.language.Translation;

import std;

// Export concrete translation modules
export import ecoscore.language.translations.en;
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

}