// tests/ecoscore/meta/TupleTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.meta;

using namespace ecoscore::meta;

TEST_CASE("tuple_concat concatenates two tuples", "[Tuple]") {
    using T1 = std::tuple<int, double>;
    using T2 = std::tuple<char, bool>;
    using Result = tuple_concat_t<T1, T2>;
    using Expected = std::tuple<int, double, char, bool>;

    STATIC_REQUIRE(std::is_same_v<Result, Expected>);
}

TEST_CASE("tuple_concat_many concatenates multiple tuples", "[Tuple]") {
    using T1 = std::tuple<int>;
    using T2 = std::tuple<double, char>;
    using T3 = std::tuple<bool>;

    using Result = tuple_concat_many_t<T1, T2, T3>;
    using Expected = std::tuple<int, double, char, bool>;

    STATIC_REQUIRE(std::is_same_v<Result, Expected>);
}
