// tests/ecoscore/type/TemplateTypeTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.type;

using namespace ecoscore::type;

struct MyType : TemplateType<MyType> {};

TEST_CASE("TemplateType provides type name and prints", "[TemplateType]") {
    MyType mt;
    std::ostringstream oss;
    oss << mt;
    REQUIRE(!oss.str().empty());

    constexpr auto name = MyType::name();
    STATIC_REQUIRE(name.size() > 0);
}
