// tests/ecoscore/type/TestStructType.cpp
/**
 * @file TestStructType.cpp
 * @brief Tests for ecoscore::type::StructType polymorphic behavior.
 */

import ecoscore.type;
#include <catch2/catch.hpp>
#include <sstream>

struct MyStruct final : ecoscore::type::StructType {
    void print(std::ostream& os) const noexcept override {
        os << "MyStruct";
    }
};

TEST_CASE("StructType polymorphic print") {
    MyStruct s;
    std::ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "MyStruct");
}
