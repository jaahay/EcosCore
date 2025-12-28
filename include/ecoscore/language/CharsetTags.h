// include/ecoscore/language/CharsetTags.h
#ifndef ECOSCORE_LANGUAGE_CHARSET_TAGS_H
#define ECOSCORE_LANGUAGE_CHARSET_TAGS_H

#include "TextRepresentations.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"

namespace ecoscore::language {

    /**
     * @brief Charset category derives from TextRepresentation.
     *
     * Represents character repertoires (sets of characters).
     */
    struct Charset : TextRepresentation {
    protected:
        constexpr Charset() noexcept = default;
    };

    /**
     * @brief Concrete charset tags specific to character repertoires.
     */

    struct Latin1 : type::TemplateType<Latin1, Charset> {
        static constexpr std::string_view name() noexcept { return "Latin-1"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Latin-1",
                "latin1",
                "latin_1",
                "ISO Latin-1 character set",
                "L****1",
                "Lat1...",
                {{"en", {{"Latin-1", "UTF-8"}}},
                 {"fr", {{"Latin-1", "UTF-8"}}}}
            };
        }
    };

    struct Cyrillic : type::TemplateType<Cyrillic, Charset> {
        static constexpr std::string_view name() noexcept { return "Cyrillic"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Cyrillic",
                "cyrillic",
                "cyrillic",
                "Cyrillic character set",
                "C*******",
                "Cyrl...",
                {{"en", {{"Cyrillic", "UTF-8"}}},
                 {"ru", {{"Кириллица", "UTF-8"}}}}
            };
        }
    };

    struct Emoji : type::TemplateType<Emoji, Charset> {
        static constexpr std::string_view name() noexcept { return "Emoji"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Emoji",
                "emoji",
                "emoji",
                "Emoji character set",
                "E****",
                "Emoj...",
                {{"en", {{"Emoji", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_CHARSET_TAGS_H
