// File: ecoscore/integrations/APIServiceTags.h
// include/ecoscore/integration/APIServiceTags.h
#ifndef ECOSCORE_INTEGRATIONS_APISERVICETAGS_H
#define ECOSCORE_INTEGRATIONS_APISERVICETAGS_H

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

#endif // ECOSCORE_INTEGRATIONS_APISERVICETAGS_H
