// include/ecoscore/integration/FileStorageTags.h
#ifndef ECOSCORE_INTEGRATION_FILESTORAGE_TAGS_H
#define ECOSCORE_INTEGRATION_FILESTORAGE_TAGS_H

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

#endif // ECOSCORE_INTEGRATION_FILESTORAGE_TAGS_H
