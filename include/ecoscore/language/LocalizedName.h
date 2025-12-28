// include/ecoscore/language/LocalizedName.h
#ifndef ECOSCORE_LANGUAGE_LOCALIZED_NAME_H
#define ECOSCORE_LANGUAGE_LOCALIZED_NAME_H

#include <string_view>

namespace ecoscore::language {

    /**
     * @brief Represents a localized name with optional charset information.
     */
    struct LocalizedName {
        std::string_view name;
        std::string_view charset; ///< e.g., "UTF-8"

        /**
         * @brief Constructs a LocalizedName.
         *
         * @param n Name string view.
         * @param cs Charset string view, default "UTF-8".
         */
        constexpr LocalizedName(std::string_view n = "", std::string_view cs = "UTF-8") noexcept
            : name(n), charset(cs) {
        }
    };

} // namespace ecoscore::language

#endif // ECOSCORE_LANGUAGE_LOCALIZED_NAME_H
