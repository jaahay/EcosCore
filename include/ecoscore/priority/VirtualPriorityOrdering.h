// include/ecoscore/priority/VirtualPriorityOrdering.h
#ifndef ECOSCORE_PRIORITY_VIRTUAL_PRIORITY_ORDERING_H
#define ECOSCORE_PRIORITY_VIRTUAL_PRIORITY_ORDERING_H

#include "ecoscore/type/StructType.h"
#include <vector>
#include <typeindex>

namespace ecoscore::priority {

    /**
     * @brief Abstract base class for priority ordering implementations.
     *
     * Defines interface for querying immediate priority dependencies.
     */
    struct VirtualPriorityOrdering : ecoscore::type::StructType {
        virtual ~VirtualPriorityOrdering() = default;

        /**
         * @brief Returns vector of priority types this priority is immediately after.
         *
         * @return const std::vector<std::type_index>& immediate dependencies.
         */
        virtual const std::vector<std::type_index>& ImmediatelyAfter() const noexcept = 0;
    };

} // namespace ecoscore::priority

#endif // ECOSCORE_PRIORITY_VIRTUAL_PRIORITY_ORDERING_H
