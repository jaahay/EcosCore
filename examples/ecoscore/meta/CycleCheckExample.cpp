// examples/ecoscore/meta/CycleCheckExample.cpp
/**
 * @file CycleCheckExample.cpp
 * @brief Demonstrates compile-time cycle detection using ecoscore::meta::CheckNoCycle.
 */

import ecoscore.meta;
#include <iostream>

int main() {
    namespace em = ecoscore::meta;

    // Define simple types with acyclic HigherThanList dependencies
    struct NodeA {
        using HigherThanList = em::TypeList<>;
    };

    struct NodeB {
        using HigherThanList = em::TypeList<NodeA>;
    };

    struct NodeC {
        using HigherThanList = em::TypeList<NodeB>;
    };

    // Compile-time check for cycles — will fail to compile if cycle exists
    constexpr bool noCycle = em::CheckNoCycle<NodeC>::value;

    std::cout << "Cycle check passed (no cycle detected): " << std::boolalpha << noCycle << "\n";

    return 0;
}
