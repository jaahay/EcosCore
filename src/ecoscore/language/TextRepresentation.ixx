// /src/ecoscore/language/TextRepresentation.ixx
export module ecoscore.language.TextRepresentation;

import std;

export import ecoscore.language.Charsets;
export import ecoscore.language.Encodings;

// Export concrete encodings
export import ecoscore.language.encoding.UTF32;
export import ecoscore.language.encoding.Windows1252;
export import ecoscore.language.encoding.MacRoman;

// Export concrete charsets
export import ecoscore.language.charset.Latin1;
export import ecoscore.language.charset.Cyrillic;
export import ecoscore.language.charset.Emoji;

// Export text representations for common encodings
export import ecoscore.language.textrepresentation.UTF8;
export import ecoscore.language.textrepresentation.UTF16;
export import ecoscore.language.textrepresentation.ISO_8859_1;
export import ecoscore.language.textrepresentation.ASCII;

namespace ecoscore::language {

    /**
     * @brief Facade module for all text representations including charsets and encodings.
     */
    struct TextRepresentationDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.language.textrepresentation";
        }
    };

}
