// File: ecoscore/localization/Localizations.h
// localization/Localizations.h
#ifndef ECOSCORE_LOCALIZATION_LOCALIZATIONS_H
#define ECOSCORE_LOCALIZATION_LOCALIZATIONS_H

#include "ecoscore/tag/Category.h"
#include "language/Locale.h"
#include "language/Languages.h"
#include "language/NameSet.h"
#include <string_view>

namespace ecoscore::localization {

    /**
     * @brief Localization data for a given Category tag and Locale.
     *
     * Specialize this template per tag and locale combination.
     */
    template <typename CategoryTag, typename LocaleTag>
    struct Localization {
        static_assert(concepts::Category<CategoryTag>, "CategoryTag must satisfy Category");
        static_assert(concepts::Locale<LocaleTag>, "LocaleTag must satisfy Locale");

        // Must be specialized to provide localized names
        static constexpr language::NameSet names = {};
    };

} // namespace ecoscore::localization

#endif // ECOSCORE_LOCALIZATION_LOCALIZATIONS_H
