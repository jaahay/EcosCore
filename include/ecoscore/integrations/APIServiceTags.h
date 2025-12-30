// include/ecoscore/integration/APIServiceTags.h
#ifndef ECOSCORE_INTEGRATION_APISERVICE_TAGS_H
#define ECOSCORE_INTEGRATION_APISERVICE_TAGS_H

/**
 * @file APIServiceTags.h
 * @brief Abstract base tag for API service integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for API service integrators.
     */
    struct APIService : tag::TagStruct<APIService> {
    protected:
        constexpr APIService() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_INTEGRATION_APISERVICE_TAGS_H
