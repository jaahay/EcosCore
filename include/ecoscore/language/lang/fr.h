// include/ecoscore/language/lang/fr.h
#ifndef ECOSCORE_LANGUAGE_LANG_FR_H
#define ECOSCORE_LANGUAGE_LANG_FR_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    /**
     * @brief French language tag.
     */
    struct fr : type::TemplateType<fr, ecoscore::language::Language> {
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

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_FR_H
