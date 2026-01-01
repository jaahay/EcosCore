// File: ecoscore/integrations/FileStorageTags.h
// include/ecoscore/integration/FileStorageTags.h
#ifndef ECOSCORE_ECOSCORE_INTEGRATIONS_FILESTORAGETAGS_H
#define ECOSCORE_ECOSCORE_INTEGRATIONS_FILESTORAGETAGS_H

/**
 * @file FileStorageTags.h
 * @brief Abstract base tag for file storage integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for file storage integrators.
     */
    struct FileStorage : tag::TagStruct<FileStorage> {
    protected:
        constexpr FileStorage() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_ECOSCORE_INTEGRATIONS_FILESTORAGETAGS_H
