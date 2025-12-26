# tests/examples/CMakeLists.txt

find_package(GTest REQUIRED)

add_executable(TestExamples
    ExampleTest1.cpp
    # Add your test-driven example source files here
)

target_link_libraries(TestExamples PRIVATE GTest::gtest_main EcosCore::event-core EcosCore::state EcosCore::concepts)

include(GoogleTest)
gtest_discover_tests(TestExamples)
