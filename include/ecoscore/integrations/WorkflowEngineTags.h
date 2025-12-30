// include/ecoscore/integration/WorkflowEngineTags.h
#ifndef ECOSCORE_INTEGRATION_WORKFLOWENGINE_TAGS_H
#define ECOSCORE_INTEGRATION_WORKFLOWENGINE_TAGS_H

/**
 * @file WorkflowEngineTags.h
 * @brief Abstract base tag for workflow engine integrators.
 */

#include "ecoscore/tag/TagStruct.h"

namespace ecoscore::integration {

    /**
     * @brief Abstract base tag for workflow engine integrators.
     */
    struct WorkflowEngine : tag::TagStruct<WorkflowEngine> {
    protected:
        constexpr WorkflowEngine() noexcept = default;
    };

} // namespace ecoscore::integration

#endif // ECOSCORE_INTEGRATION_WORKFLOWENGINE_TAGS_H
