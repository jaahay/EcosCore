// EcosCore/tag/LanguageTags.h
#ifndef ECOSCORE_TAG_LANGUAGE_TAGS_H
#define ECOSCORE_TAG_LANGUAGE_TAGS_H

#include "EcosCore/tag/Tag.h"
#include "EcosCore/type/TemplateType.h"
#include "EcosCore/tag/NameSet.h"

namespace EcosCore::tag {

    /** Abstract Language category */
    struct Language : Tag<Language> {
    protected:
        constexpr Language() noexcept = default;
    };

    /** Concrete Language tags */
    namespace lang {

        struct en : type::TemplateType<en, Language> {
            static constexpr std::string_view name() noexcept { return "English"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "English",
                    "english",
                    "en",
                    "English language",
                    "E*****h",
                    "Eng...",
                    {{"en", {{"English", "UTF-8"}}},
                     {"fr", {{"Anglais", "UTF-8"}}}}
                };
            }
        };

        struct fr : type::TemplateType<fr, Language> {
            static constexpr std::string_view name() noexcept { return "French"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "French",
                    "french",
                    "fr",
                    "Langue française",
                    "F*****h",
                    "Fre...",
                    {{"fr", {{"Français", "UTF-8"}}},
                     {"en", {{"French", "UTF-8"}}}}
                };
            }
        };

        struct es : type::TemplateType<es, Language> {
            static constexpr std::string_view name() noexcept { return "Spanish"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "Spanish",
                    "spanish",
                    "es",
                    "Idioma español",
                    "S*****h",
                    "Spa...",
                    {{"es", {{"Español", "UTF-8"}}},
                     {"en", {{"Spanish", "UTF-8"}}}}
                };
            }
        };

        struct de : type::TemplateType<de, Language> {
            static constexpr std::string_view name() noexcept { return "German"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "German",
                    "german",
                    "de",
                    "Deutsche Sprache",
                    "G*****n",
                    "Ger...",
                    {{"de", {{"Deutsch", "UTF-8"}}},
                     {"en", {{"German", "UTF-8"}}}}
                };
            }
        };

        struct zh : type::TemplateType<zh, Language> {
            static constexpr std::string_view name() noexcept { return "Chinese"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "Chinese",
                    "chinese",
                    "zh",
                    "中文",
                    "C*****e",
                    "Chi...",
                    {{"zh", {{"中文", "UTF-8"}}},
                     {"en", {{"Chinese", "UTF-8"}}}}
                };
            }
        };

        struct ar : type::TemplateType<ar, Language> {
            static constexpr std::string_view name() noexcept { return "Arabic"; }
            static constexpr NameSet names() noexcept {
                return NameSet{
                    "Arabic",
                    "arabic",
                    "ar",
                    "اللغة العربية",
                    "A*****c",
                    "Ara...",
                    {{"ar", {{"اللغة العربية", "UTF-8"}}},
                     {"en", {{"Arabic", "UTF-8"}}}}
                };
            }
        };

    } // namespace lang

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_LANGUAGE_TAGS_H
