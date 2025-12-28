// include/ecoscore/language/lang/en.h
#ifndef ECOSCORE_LANGUAGE_LANG_EN_H
#define ECOSCORE_LANGUAGE_LANG_EN_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    /**
     * @brief English language tag.
     */
    struct en : type::TemplateType<en, ecoscore::language::Language> {
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

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_EN_H
