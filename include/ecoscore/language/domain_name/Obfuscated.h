// language/domain_name/ExternalId.h
#ifndef ECOSCORE_LANGUAGE_DOMAIN_NAME_EXTERNALID_H
#define ECOSCORE_LANGUAGE_DOMAIN_NAME_EXTERNALID_H

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

}  // namespace ecoscore::language::domain_name

#endif  // ECOSCORE_LANGUAGE_DOMAIN_NAME_EXTERNALID_H
