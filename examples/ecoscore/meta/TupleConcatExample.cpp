// examples/ecoscore/meta/TupleConcatExample.cpp
/**
 * @file TupleConcatExample.cpp
 * @brief Demonstrates compile-time concatenation of std::tuple types using ecoscore::meta utilities.
 */

import ecoscore.meta;
#include <iostream>
#include <tuple>
#include <type_traits>

int main() {
    namespace em = ecoscore::meta;

    using Tuple1 = std::tuple<int, double>;
    using Tuple2 = std::tuple<char, bool>;
    using Tuple3 = std::tuple<float>;

    // Concatenate two tuples
    using ConcatenatedTwo = em::tuple_concat_t<Tuple1, Tuple2>;
    static_assert(std::is_same_v<ConcatenatedTwo, std::tuple<int, double, char, bool>>);

    // Concatenate multiple tuples
    using ConcatenatedMany = em::tuple_concat_many_t<Tuple1, Tuple2, Tuple3>;
    static_assert(std::is_same_v<ConcatenatedMany, std::tuple<int, double, char, bool, float>>);

    std::cout << "Tuple concatenation example compiled successfully.\n";

    return 0;
}
