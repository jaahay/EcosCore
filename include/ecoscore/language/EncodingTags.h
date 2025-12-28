// include/ecoscore/language/EncodingTags.h
#ifndef ECOSCORE_LANGUAGE_ENCODING_TAGS_H
#define ECOSCORE_LANGUAGE_ENCODING_TAGS_H

#include "TextRepresentations.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"

namespace ecoscore::language {

    /**
     * @brief Encoding category derives from TextRepresentation.
     *
     * Represents byte-level encoding schemes for character sets.
     */
    struct Encoding : TextRepresentation {
    protected:
        constexpr Encoding() noexcept = default;
    };

    /**
     * @brief Concrete encoding tags specific to serialization formats.
     */

    struct UTF32 : type::TemplateType<UTF32, Encoding> {
        static constexpr std::string_view name() noexcept { return "UTF-32"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "UTF-32",
                "utf32",
                "UTF32",
                "Unicode Transformation Format - 32 bit",
                "U***2",
                "UTF-32...",
                {{"en", {{"UTF-32", "UTF-8"}}}}
            };
        }
    };

    struct Windows1252 : type::TemplateType<Windows1252, Encoding> {
        static constexpr std::string_view name() noexcept { return "Windows-1252"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Windows-1252",
                "windows1252",
                "win1252",
                "Windows Western European encoding",
                "W*******",
                "Win12...",
                {{"en", {{"Windows-1252", "UTF-8"}}}}
            };
        }
    };

    struct MacRoman : type::TemplateType<MacRoman, Encoding> {
        static constexpr std::string_view name() noexcept { return "MacRoman"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "MacRoman",
                "macroman",
                "mac_roman",
                "Macintosh Roman encoding",
                "M*******",
                "MacRo...",
                {{"en", {{"MacRoman", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_ENCODING_TAGS_H
