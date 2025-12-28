// EcosCore/tag/CharsetTags.h
#ifndef ECOSCORE_TAG_CHARSET_TAGS_H
#define ECOSCORE_TAG_CHARSET_TAGS_H

#include "EcosCore/tag/Tag.h"
#include "EcosCore/type/TemplateType.h"
#include "EcosCore/tag/NameSet.h"

namespace EcosCore::tag {

    /** Abstract Charset category */
    struct Charset : Tag<Charset> {
    protected:
        constexpr Charset() noexcept = default;
    };

    /** Concrete Charset tags */
    namespace charset {

        struct UTF8 : type::TemplateType<UTF8, Charset> {
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

        struct ISO_8859_1 : type::TemplateType<ISO_8859_1, Charset> {
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

        struct ASCII : type::TemplateType<ASCII, Charset> {
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

        struct UTF16 : type::TemplateType<UTF16, Charset> {
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

    } // namespace charset

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_CHARSET_TAGS_H
