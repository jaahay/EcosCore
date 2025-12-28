// examples/ecoscore/meta/TypeListExample.cpp
/**
 * @file TypeListExample.cpp
 * @brief Demonstrates usage of ecoscore::meta::TypeList and Contains.
 */

import ecoscore.meta;
#include <iostream>

int main() {
    namespace em = ecoscore::meta;

    using MyList = em::TypeList<int, double, char>;
    constexpr bool contains_double = em::Contains<double, MyList>::value;
    constexpr bool contains_float = em::Contains<float, MyList>::value;

    std::cout << "Contains double: " << contains_double << "\n";
    std::cout << "Contains float: " << contains_float << "\n";

    return 0;
}
