// include/ecoscore/language/TextRepresentations.h
#ifndef ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
#define ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"

namespace ecoscore::language {

    /**
     * @brief Common base tag for all text representation categories.
     */
    struct TextRepresentation : tag::Tag<TextRepresentation> {
    protected:
        constexpr TextRepresentation() noexcept = default;
    };

    /**
     * @brief Concrete text representation tags shared by Charset and Encoding.
     *
     * These represent widely used character sets and encodings.
     */

    struct UTF8 : type::TemplateType<UTF8, TextRepresentation> {
        static constexpr std::string_view name() noexcept { return "UTF-8"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "UTF-8",
                "utf8",
                "UTF8",
                "Unicode Transformation Format - 8 bit",
                "U***8",
                "UTF-8...",
                {{"en", {{"UTF-8", "UTF-8"}}},
                 {"fr", {{"UTF-8", "UTF-8"}}}}
            };
        }
    };

    struct ISO_8859_1 : type::TemplateType<ISO_8859_1, TextRepresentation> {
        static constexpr std::string_view name() noexcept { return "ISO-8859-1"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "ISO-8859-1",
                "iso8859-1",
                "ISO_8859_1",
                "Western European (Latin-1)",
                "I***1",
                "ISO-8859...",
                {{"en", {{"ISO-8859-1", "UTF-8"}}},
                 {"fr", {{"ISO-8859-1", "UTF-8"}}}}
            };
        }
    };

    struct ASCII : type::TemplateType<ASCII, TextRepresentation> {
        static constexpr std::string_view name() noexcept { return "ASCII"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "ASCII",
                "ascii",
                "ASCII",
                "American Standard Code for Information Interchange",
                "A***I",
                "ASCII",
                {{"en", {{"ASCII", "UTF-8"}}}}
            };
        }
    };

    struct UTF16 : type::TemplateType<UTF16, TextRepresentation> {
        static constexpr std::string_view name() noexcept { return "UTF-16"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "UTF-16",
                "utf16",
                "UTF16",
                "Unicode Transformation Format - 16 bit",
                "U***6",
                "UTF-16...",
                {{"en", {{"UTF-16", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_TEXTREPRESENTATIONS_H
