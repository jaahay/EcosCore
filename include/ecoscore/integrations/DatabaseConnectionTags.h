// include/ecoscore/integration/DatabaseConnectionTags.h
#ifndef ECOSCORE_INTEGRATION_DATABASE_CONNECTION_TAGS_H
#define ECOSCORE_INTEGRATION_DATABASE_CONNECTION_TAGS_H

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

#endif // ECOSCORE_INTEGRATION_DATABASE_CONNECTION_TAGS_H
