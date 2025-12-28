// include/ecoscore/language/lang/ar.h
#ifndef ECOSCORE_LANGUAGE_LANG_AR_H
#define ECOSCORE_LANGUAGE_LANG_AR_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    /**
     * @brief Arabic language tag.
     */
    struct ar : type::TemplateType<ar, ecoscore::language::Language> {
        static constexpr std::string_view name() noexcept { return "Arabic"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Arabic",
                "arabic",
                "ar",
                "العربية",
                "A****",
                "Ara...",
                {{"ar", {{"العربية", "UTF-8"}}},
                 {"en", {{"Arabic", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_AR_H
