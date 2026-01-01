// File: ecoscore/integrations/MessageBrokerTags.h
// include/ecoscore/integration/MessageBrokerTags.h
#ifndef ECOSCORE_ECOSCORE_INTEGRATIONS_MESSAGEBROKERTAGS_H
#define ECOSCORE_ECOSCORE_INTEGRATIONS_MESSAGEBROKERTAGS_H

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

#endif // ECOSCORE_ECOSCORE_INTEGRATIONS_MESSAGEBROKERTAGS_H
