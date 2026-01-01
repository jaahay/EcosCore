// File: ecoscore/integrations/DatabaseConnectionTags.h
// include/ecoscore/integration/DatabaseConnectionTags.h
#ifndef ECOSCORE_ECOSCORE_INTEGRATIONS_DATABASECONNECTIONTAGS_H
#define ECOSCORE_ECOSCORE_INTEGRATIONS_DATABASECONNECTIONTAGS_H

/**
 * @file DatabaseConnectionTags.h
 * @brief Abstract base tag for database connection integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for database connection integrators.
     */
    struct DatabaseConnection : tag::TagStruct<DatabaseConnection> {
    protected:
        constexpr DatabaseConnection() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_ECOSCORE_INTEGRATIONS_DATABASECONNECTIONTAGS_H
