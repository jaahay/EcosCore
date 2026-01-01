// File: ecoscore/integrations/WorkflowEngineTags.h
// include/ecoscore/integration/WorkflowEngineTags.h
#ifndef ECOSCORE_INTEGRATIONS_WORKFLOWENGINETAGS_H
#define ECOSCORE_INTEGRATIONS_WORKFLOWENGINETAGS_H

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

#endif // ECOSCORE_INTEGRATIONS_WORKFLOWENGINETAGS_H
