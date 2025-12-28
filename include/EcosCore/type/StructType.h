// EcosCore/type/StructType.h
#ifndef ECOSCORE_TYPE_STRUCT_TYPE_H
#define ECOSCORE_TYPE_STRUCT_TYPE_H

#include <iostream>

namespace ecoscore::type {

    /**
     * Base struct type for polymorphic hierarchy or tagging.
     */
    struct StructType {
        virtual ~StructType() = default;

        virtual void print(std::ostream& os) const = 0;

        friend std::ostream& operator<<(std::ostream& os, const StructType& obj) {
            obj.print(os);
            return os;
        }
    };

} // namespace ecoscore::type

#endif // ECOSCORE_TYPE_STRUCT_TYPE_H
