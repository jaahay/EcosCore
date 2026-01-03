cmake_minimum_required(VERSION 3.28)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tools)

add_subdirectory(src/meta)
#add_subdirectory(apps/meta)
add_smoke_test_for_headers(meta)

add_subdirectory(src/category)
#add_subdirectory(apps/category)
add_smoke_test_for_headers(category)

add_subdirectory(src/language)
target_link_libraries(language INTERFACE category)
#add_subdirectory(apps/language)
add_smoke_test_for_headers(language)

add_subdirectory(src/flow)
target_link_libraries(flow INTERFACE category)
target_link_libraries(flow INTERFACE language)
add_smoke_test_for_headers(flow)

add_subdirectory(src/outcome)
target_link_libraries(outcome INTERFACE category)
#target_link_libraries(outcome INTERFACE language)
add_smoke_test_for_headers(outcome)

add_subdirectory(src/phase)
target_link_libraries(phase INTERFACE category)
#target_link_libraries( INTERFACE language)
add_smoke_test_for_headers(phase)