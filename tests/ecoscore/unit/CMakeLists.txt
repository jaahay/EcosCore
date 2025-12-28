# tests/unit/CMakeLists.txt

find_package(GTest REQUIRED)

add_executable(UnitTests
    UnitTest1.cpp
    #UnitTest2.cpp
    # Add your unit test source files here
)

target_link_libraries(UnitTests PRIVATE GTest::gtest_main EcosCore::event-core EcosCore::state EcosCore::concepts)

include(GoogleTest)
gtest_discover_tests(UnitTests)