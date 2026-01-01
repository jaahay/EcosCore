// File: ecoscore/language/domain_name/Obfuscated.h
// language/domain_name/ExternalId.h
#ifndef ECOSCORE_ECOSCORE_LANGUAGE_DOMAIN_NAME_OBFUSCATED_H
#define ECOSCORE_ECOSCORE_LANGUAGE_DOMAIN_NAME_OBFUSCATED_H

#include <string_view>

namespace ecoscore::language::domain_name {

    /**
     * @brief External integration identifier for a tag.
     * Specialize per tag as needed.
     */
    template <typename Tag>
    struct ExternalId {
        static constexpr std::string_view value = "";
    };

} // namespace ecoscore::language::domain_name

#endif // ECOSCORE_ECOSCORE_LANGUAGE_DOMAIN_NAME_OBFUSCATED_H
