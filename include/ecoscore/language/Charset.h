// /src/ecoscore/language/Charset.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_CHARSET_IXX__
#define __SRC_ECOSCORE_LANGUAGE_CHARSET_IXX__

#include "std.h"

#include "ecoscore/language/lang/en.h"
#include "ecoscore/language/lang/fr.h"
#include "ecoscore/language/lang/de.h"
#include "ecoscore/language/lang/es.h"
#include "ecoscore/language/lang/zh_hans.h"
#include "ecoscore/language/lang/zh_hant.h"
#include "ecoscore/language/lang/ja.h"
#include "ecoscore/language/lang/ko.h"
#include "ecoscore/language/lang/ar.h"

namespace ecoscore::language::lang {

    /**
     * @brief Facade module exporting all language tags.
     */
    struct LangDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.language.lang";
        }
    };

}
#endif // __SRC_ECOSCORE_LANGUAGE_CHARSET_IXX__
