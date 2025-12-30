// include/ecoscore/integration/ExternalServiceTags.h
#ifndef ECOSCORE_INTEGRATION_EXTERNALSERVICE_TAGS_H
#define ECOSCORE_INTEGRATION_EXTERNALSERVICE_TAGS_H

/**
 * @file ExternalServiceTags.h
 * @brief Abstract base tag for external service integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for external service integrators.
     */
    struct ExternalService : tag::TagStruct<ExternalService> {
    protected:
        constexpr ExternalService() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_INTEGRATION_EXTERNALSERVICE_TAGS_H
