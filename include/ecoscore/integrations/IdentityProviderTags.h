// include/ecoscore/integration/IdentityProviderTags.h
#ifndef ECOSCORE_INTEGRATION_IDENTITYPROVIDER_TAGS_H
#define ECOSCORE_INTEGRATION_IDENTITYPROVIDER_TAGS_H

/**
 * @file IdentityProviderTags.h
 * @brief Abstract base tag for identity provider integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for identity provider integrators.
     */
    struct IdentityProvider : tag::TagStruct<IdentityProvider> {
    protected:
        constexpr IdentityProvider() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_INTEGRATION_IDENTITYPROVIDER_TAGS_H
