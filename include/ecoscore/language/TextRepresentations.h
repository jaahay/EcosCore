// File: ecoscore/language/TextRepresentations.h
// /src/ecoscore/language/TextRepresentations.ixx
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H



#include "ecoscore/language/Charsets.h"
#include "ecoscore/language/Encodings.h"

// Export concrete encodings
#include "ecoscore/language/encoding/UTF32.h"
#include "ecoscore/language/encoding/Windows1252.h"
#include "ecoscore/language/encoding/MacRoman.h"

// Export concrete charsets
#include "ecoscore/language/charset/Latin1.h"
#include "ecoscore/language/charset/Cyrillic.h"
#include "ecoscore/language/charset/Emoji.h"

// Export text representations for common encodings
#include "ecoscore/language/textrepresentation/UTF8.h"
#include "ecoscore/language/textrepresentation/UTF16.h"
#include "ecoscore/language/textrepresentation/ISO_8859_1.h"
#include "ecoscore/language/textrepresentation/ASCII.h"

namespace ecoscore::language {

    /**
     * @brief Facade module for all text representations including charsets and encodings.
     */
    struct TextRepresentationDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.language.textrepresentation";
} // namespace ecoscore::language
    };

}#endif // __SRC_ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_IXX__
#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
