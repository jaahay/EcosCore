// EcosCore/tag/PriorityOrderingBase.h
#ifndef ECOSCORE_TAG_PRIORITY_ORDERING_BASE_H
#define ECOSCORE_TAG_PRIORITY_ORDERING_BASE_H

#include "EcosCore/type/StructType.h"
#include <vector>
#include <typeindex>

namespace EcosCore::tag {

    /**
     * Abstract base for priority ordering implementations.
     * Defines interface for querying immediate dependencies.
     */
    struct PriorityOrderingBase : EcosCore::type::StructType {
        virtual ~PriorityOrderingBase() = default;

        /**
         * @return vector of priority types this priority is immediately after.
         */
        virtual const std::vector<std::type_index>& ImmediatelyAfter() const noexcept = 0;
    };

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_PRIORITY_ORDERING_BASE_H
