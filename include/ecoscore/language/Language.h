// File: ecoscore/language/Language.h
#ifndef ECOSCORE_LANGUAGE_LANGUAGE_H_
#define ECOSCORE_LANGUAGE_LANGUAGE_H_

#include "ecoscore/category/Category.h"

namespace ecoscore::language {

    /**
     * @brief Base category for all languages.
     *
     * Abstract, non-instantiable tag.
     */
    struct Language : ecoscore::category::Category {
    protected:
        constexpr Language() noexcept = default;

    public:
        Language(const Language&) = delete;
        Language& operator=(const Language&) = delete;
        ~Language() noexcept = default;

        static constexpr std::string_view name() noexcept { return "Language"; }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_LANGUAGE_H_
