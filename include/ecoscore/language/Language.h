//// File: EcosCore/src/ecoscore/language/Language.ixx
#ifndef __SRC_ECOSCORE_LANGUAGE_LANGUAGE_IXX__
#define __SRC_ECOSCORE_LANGUAGE_LANGUAGE_IXX__

#include "ecoscore/category/Category.h"

namespace ecoscore::language {

    /**
     * @brief Base category for all languages.
     * Static-only design: no virtual functions.
     */
struct Language : ecoscore::category::Category {
        Language() noexcept = default;
        Language(const Language&) = delete;
        Language& operator=(const Language&) = delete;
        Language(Language&&) = delete;
        Language& operator=(Language&&) = delete;
        ~Language() noexcept = default;
    };

} // namespace ecoscore::language
#endif // __SRC_ECOSCORE_LANGUAGE_LANGUAGE_IXX__
