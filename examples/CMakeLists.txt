# examples/CMakeLists.txt

add_executable(IntegrationExample IntegrationTest.cpp)
target_link_libraries(IntegrationExample PRIVATE EcosCore::event-core EcosCore::state EcosCore::concepts)

add_executable(basic_usage examples/basic_usage.cpp)
target_link_libraries(basic_usage PRIVATE EcosCore::event-core EcosCore::state)

add_executable(async_callbacks examples/async_callbacks.cpp)
target_link_libraries(async_callbacks PRIVATE EcosCore::event-core EcosCore::state)

add_executable(utility_callbacks examples/utility_callbacks.cpp)
target_link_libraries(utility_callbacks PRIVATE EcosCore::event-util EcosCore::event-core EcosCore::state)
