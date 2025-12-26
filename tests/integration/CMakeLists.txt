# tests/integration/CMakeLists.txt

find_package(GTest REQUIRED)

add_executable(IntegrationTests
    IntegrationTest1.cpp
    # Add your integration test source files here
)

target_link_libraries(IntegrationTests PRIVATE GTest::gtest_main EcosCore::event-core EcosCore::state EcosCore::concepts)

include(GoogleTest)
gtest_discover_tests(IntegrationTests)
