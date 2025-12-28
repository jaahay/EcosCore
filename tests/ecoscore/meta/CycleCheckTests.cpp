// tests/ecoscore/meta/CycleCheckTests.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
import ecoscore.meta;

namespace em = ecoscore::meta;

struct A { using HigherThanList = em::TypeList<>; };
struct B { using HigherThanList = em::TypeList<A>; };
struct C { using HigherThanList = em::TypeList<B>; };
struct D { using HigherThanList = em::TypeList<C>; };

TEST_CASE("CheckNoCycle detects acyclic types", "[CycleCheck]") {
    STATIC_REQUIRE(em::CheckNoCycle<A>::value);
    STATIC_REQUIRE(em::CheckNoCycle<B>::value);
    STATIC_REQUIRE(em::CheckNoCycle<C>::value);
    STATIC_REQUIRE(em::CheckNoCycle<D>::value);
}

// Note: Cycle detection triggers static_assert and compile error,
// so testing cycles requires separate compile-fail tests or SFINAE tricks.
