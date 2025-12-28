// tests/ecoscore/meta/VariantTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.meta;

using namespace ecoscore::meta;

TEST_CASE("tuple_to_variant converts tuple to variant", "[Variant]") {
    using Tuple = std::tuple<int, double, char>;
    using Variant = tuple_to_variant_t<Tuple>;
    using Expected = std::variant<int, double, char>;

    STATIC_REQUIRE(std::is_same_v<Variant, Expected>);
}

TEST_CASE("variant_concat concatenates variants", "[Variant]") {
    using V1 = std::variant<int, double>;
    using V2 = std::variant<char, bool>;
    using Result = variant_concat_t<V1, V2>;
    using Expected = std::variant<int, double, char, bool>;

    STATIC_REQUIRE(std::is_same_v<Result, Expected>);
}
