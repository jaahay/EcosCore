// EcosCore/test/examples/meta/ExampleCycleCheck.cpp
#include "../../meta/TypeList.h"
#include "../../meta/CycleCheck.h"

namespace ecoscore::meta {

    // Sample priority tags with HigherThanList declarations to represent ordering
    struct PriorityA {
        using HigherThanList = TypeList<>;
    };

    struct PriorityB {
        using HigherThanList = TypeList<PriorityA>;
    };

    struct PriorityC {
        using HigherThanList = TypeList<PriorityB>;
    };

    // Uncommenting this will cause a cycle and a static_assert failure
    /*
    struct PriorityCycle {
        using HigherThanList = TypeList<PriorityC>;
    };

    struct PriorityC {
        using HigherThanList = TypeList<PriorityCycle>;
    };
    */

    static_assert(CheckNoCycle<PriorityA>::value, "No cycle for PriorityA");
    static_assert(CheckNoCycle<PriorityB>::value, "No cycle for PriorityB");
    static_assert(CheckNoCycle<PriorityC>::value, "No cycle for PriorityC");

} // namespace ecoscore::meta

int main() {
    // This example is compile-time only; no runtime code needed.
    return 0;
}
