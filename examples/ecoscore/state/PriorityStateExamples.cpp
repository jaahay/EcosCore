// examples/state/PriorityExamples.cpp

#include <iostream>
#include "EcosCore/state/DefaultPriorityTags.h"

using namespace ecoscore::state;

int main() {
    auto& high = HigherPriority::instance();
    auto& defaultP = DefaultPriority::instance();

    std::cout << "High priority: " << high.name() << "\n";
    std::cout << "Default priority: " << defaultP.name() << "\n";

    return 0;
}
