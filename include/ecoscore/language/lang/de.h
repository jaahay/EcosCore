// include/ecoscore/language/lang/de.h
#ifndef ECOSCORE_LANGUAGE_LANG_DE_H
#define ECOSCORE_LANGUAGE_LANG_DE_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    /**
     * @brief German language tag.
     */
    struct de : type::TemplateType<de, ecoscore::language::Language> {
        static constexpr std::string_view name() noexcept { return "German"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "German",
                "german",
                "de",
                "Deutsche Sprache",
                "G*****",
                "Ger...",
                {{"de", {{"Deutsch", "UTF-8"}}},
                 {"en", {{"German", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_DE_H
