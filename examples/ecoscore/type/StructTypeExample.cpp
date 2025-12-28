// examples/ecoscore/type/StructTypeExample.cpp
/**
 * @file StructTypeExample.cpp
 * @brief Demonstrates polymorphic usage of ecoscore::type::StructType.
 */

import ecoscore.type;
#include <iostream>

struct ConcreteStruct : ecoscore::type::StructType {
    void print(std::ostream& os) const noexcept override {
        os << "ConcreteStruct instance";
    }
};

int main() {
    ConcreteStruct cs;
    std::cout << cs << '\n'; // Uses StructType's friend operator<<
    return 0;
}
