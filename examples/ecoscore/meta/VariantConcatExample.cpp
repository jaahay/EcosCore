// examples/ecoscore/meta/VariantConcatExample.cpp
/**
 * @file VariantConcatExample.cpp
 * @brief Demonstrates usage of ecoscore::meta::variant_concat_t to combine variants.
 */

import ecoscore.meta;
#include <iostream>
#include <variant>
#include <type_traits>

int main() {
    namespace em = ecoscore::meta;

    using V1 = std::variant<int, double>;
    using V2 = std::variant<char, bool>;
    using Combined = em::variant_concat_t<V1, V2>;

    std::cout << "Variant concatenation example compiled successfully.\n";

    static_assert(std::is_same_v<Combined, std::variant<int, double, char, bool>>);

    // Optional runtime demonstration
    Combined v = 42;
    std::cout << "Variant holds index: " << v.index() << "\n";

    return 0;
}
