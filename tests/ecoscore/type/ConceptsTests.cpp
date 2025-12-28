// tests/ecoscore/type/ConceptsTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.type;
import ecoscore.type:concepts;

using namespace ecoscore::type;
using namespace ecoscore::type::concepts;

struct Concrete : StructType {
    void print(std::ostream&) const noexcept override {}
};

struct Abstract : StructType {
    virtual void foo() = 0;
};

struct TagCategoryExample : ecoscore::tag::Tag<TagCategoryExample> {};

TEST_CASE("DerivedFromStructType concept", "[concepts]") {
    STATIC_REQUIRE(DerivedFromStructType<Concrete>);
    STATIC_REQUIRE(DerivedFromStructType<Abstract>);
    STATIC_REQUIRE_FALSE(DerivedFromStructType<int>);
}

TEST_CASE("ConcreteType concept", "[concepts]") {
    STATIC_REQUIRE(ConcreteType<Concrete>);
    STATIC_REQUIRE_FALSE(ConcreteType<Abstract>);
    STATIC_REQUIRE_FALSE(ConcreteType<int>);
}

TEST_CASE("SingletonTag concept (mock)", "[concepts]") {
    struct MockTag {
        static const MockTag& instance() noexcept {
            static MockTag inst;
            return inst;
        }
        static constexpr const char* name() noexcept { return "MockTag"; }
    };

    STATIC_REQUIRE(SingletonTag<MockTag>);
}

TEST_CASE("TagCategory concept (mock)", "[concepts]") {
    STATIC_REQUIRE(TagCategory<TagCategoryExample>);
}
