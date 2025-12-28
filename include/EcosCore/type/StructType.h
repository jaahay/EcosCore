// include/ecoscore/type/StructType.h
#ifndef ECOSCORE_TYPE_STRUCT_TYPE_H
#define ECOSCORE_TYPE_STRUCT_TYPE_H

#include <iostream>

namespace ecoscore::type {

    /**
     * @brief Base struct type for polymorphic hierarchies.
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
