// src/ecoscore/type/StructType.ixx
module ecoscore.type.StructType;

import <iostream>;

export namespace ecoscore::type {

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

}
