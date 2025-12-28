// tests/ecoscore/meta/TypeListTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.meta;

using namespace ecoscore::meta;

TEST_CASE("TypeList Contains works correctly", "[TypeList]") {
    using List = TypeList<int, double, char>;

    STATIC_REQUIRE(Contains<int, List>::value);
    STATIC_REQUIRE(Contains<double, List>::value);
    STATIC_REQUIRE(Contains<char, List>::value);
    STATIC_REQUIRE_FALSE(Contains<float, List>::value);
}

TEST_CASE("TypeList Append appends correctly", "[TypeList]") {
    using List1 = TypeList<int, double>;
    using List2 = Append<List1, char>::type;
    using Expected = TypeList<int, double, char>;

    STATIC_REQUIRE(std::is_same_v<List2, Expected>);
}
