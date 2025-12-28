// examples/ecoscore/type/TemplateTypeExample.cpp
/**
 * @file TemplateTypeExample.cpp
 * @brief Demonstrates usage of ecoscore::type::TemplateType CRTP base.
 */

import ecoscore.type;
#include <iostream>

struct MyType : ecoscore::type::TemplateType<MyType> {};

int main() {
    MyType obj;
    std::cout << obj << '\n'; // Prints the type name via operator<<
    std::cout << "Static name(): " << MyType::name() << '\n'; // Prints type name as string_view
    return 0;
}
