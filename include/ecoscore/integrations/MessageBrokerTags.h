// include/ecoscore/integration/MessageBrokerTags.h
#ifndef ECOSCORE_INTEGRATION_MESSAGEBROKER_TAGS_H
#define ECOSCORE_INTEGRATION_MESSAGEBROKER_TAGS_H

/**
 * @file MessageBrokerTags.h
 * @brief Abstract base tag for message broker integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for message broker integrators.
     */
    struct MessageBroker : tag::TagStruct<MessageBroker> {
    protected:
        constexpr MessageBroker() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_INTEGRATION_MESSAGEBROKER_TAGS_H
