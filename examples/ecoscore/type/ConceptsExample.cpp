// examples/ecoscore/type/ConceptsExample.cpp
/**
 * @file ConceptsExample.cpp
 * @brief Demonstrates ecoscore::type concepts usage.
 */

import ecoscore.type;
import ecoscore.type:concepts;
#include <iostream>

struct MyConcrete : ecoscore::type::StructType {
    void print(std::ostream& os) const noexcept override {
        os << "MyConcrete";
    }
};

struct MyTag : ecoscore::tag::Tag<MyTag> {
    static const MyTag& instance() noexcept {
        static MyTag inst;
        return inst;
    }
    static constexpr const char* name() noexcept { return "MyTag"; }
};

int main() {
    using namespace ecoscore::type::concepts;

    std::cout << "DerivedFromStructType<MyConcrete>: " << DerivedFromStructType<MyConcrete> << "\n";
    std::cout << "ConcreteType<MyConcrete>: " << ConcreteType<MyConcrete> << "\n";
    std::cout << "SingletonTag<MyTag>: " << SingletonTag<MyTag> << "\n";

    return 0;
}
