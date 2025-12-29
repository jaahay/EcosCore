// include/ecoscore/type/StructType.h
#ifndef ECOSCORE_TYPE_STRUCT_TYPE_H
#define ECOSCORE_TYPE_STRUCT_TYPE_H

#include <iostream>

namespace ecoscore::type {

    /**
     * @file StructType.h
     * @brief Base struct type for polymorphic hierarchies.
     *
     * Provides an abstract interface with a virtual print method.
     */

    struct StructType {
        virtual ~StructType() noexcept = default;

        /**
         * @brief Print the object to the output stream.
         * @param os Output stream.
         */
        virtual void print(std::ostream& os) const noexcept = 0;

        friend std::ostream& operator<<(std::ostream& os, const StructType& obj) noexcept {
            obj.print(os);
            return os;
        }
    };

} // namespace ecoscore::type

#endif // ECOSCORE_TYPE_STRUCT_TYPE_H
