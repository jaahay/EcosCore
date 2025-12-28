// include/ecoscore/language/lang/zh.h
#ifndef ECOSCORE_LANGUAGE_LANG_ZH_H
#define ECOSCORE_LANGUAGE_LANG_ZH_H

#include "ecoscore/tag/Tag.h"
#include "ecoscore/type/TemplateType.h"
#include "ecoscore/language/NameSet.h"
#include "ecoscore/language/LocalizedName.h"

namespace ecoscore::language::lang {

    /**
     * @brief Chinese language tag.
     */
    struct zh : type::TemplateType<zh, ecoscore::language::Language> {
        static constexpr std::string_view name() noexcept { return "Chinese"; }
        static constexpr NameSet names() noexcept {
            return NameSet{
                "Chinese",
                "chinese",
                "zh",
                "中文",
                "C*****",
                "Chi...",
                {{"zh", {{"中文", "UTF-8"}}},
                 {"en", {{"Chinese", "UTF-8"}}}}
            };
        }
    };

} // namespace ecoscore::language::lang

#endif // ECOSCORE_LANGUAGE_LANG_ZH_H
