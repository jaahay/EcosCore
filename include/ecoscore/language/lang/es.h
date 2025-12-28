// include/ecoscore/language/lang/es.h
#ifndef ECOSCORE_LANGUAGE_LANG_ES_H
#define ECOSCORE_LANGUAGE_LANG_ES_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    struct es : type::TemplateType<es, ecoscore::language::Language> {
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

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ES_H
