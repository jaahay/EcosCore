// tests/ecoscore/type/StructTypeTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.type;

using namespace ecoscore::type;

struct ConcreteStruct : StructType {
    void print(std::ostream&) const noexcept override {}
};

TEST_CASE("StructType polymorphic print and operator<<", "[StructType]") {
    ConcreteStruct c;
    std::ostringstream oss;
    oss << c;
    REQUIRE(!oss.str().empty());
}
