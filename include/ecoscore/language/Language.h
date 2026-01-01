// File: ecoscore/language/Language.h
//// File: EcosCore/src/ecoscore/language/Language.ixx
#ifndef ECOSCORE_LANGUAGE_LANGUAGE_H
#define ECOSCORE_LANGUAGE_LANGUAGE_H

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
#endif // ECOSCORE_LANGUAGE_LANGUAGE_H
