// File: ecoscore/priority/VirtualPriorityOrdering.h
#ifndef ECOSCORE_ECOSCORE_PRIORITY_VIRTUALPRIORITYORDERING_H
#define ECOSCORE_ECOSCORE_PRIORITY_VIRTUALPRIORITYORDERING_H
// src/ecoscore/priority/VirtualPriorityOrdering.ixx
module ecoscore.priority.VirtualPriorityOrdering;

#include "ecoscore/type/StructType.h"

namespace ecoscore::priority {

    /**
     * @brief Abstract base class for priority ordering implementations.
     */
    struct VirtualPriorityOrdering : ecoscore::type::StructType {
        virtual ~VirtualPriorityOrdering() = default;

        /**
         * @brief Returns immediate dependencies.
         */
        virtual const std::vector<std::type_index>& ImmediatelyAfter() const noexcept = 0;
    };

} // namespace ecoscore::priority
#endif // ECOSCORE_ECOSCORE_PRIORITY_VIRTUALPRIORITYORDERING_H
