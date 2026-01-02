cmake_minimum_required(VERSION 3.28)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tools)

add_subdirectory(src/meta)
add_subdirectory(apps/meta)
add_smoke_test_for_headers(meta include/ecoscore/meta)

add_subdirectory(src/category)
add_subdirectory(apps/category)
add_smoke_test_for_headers(category include/ecoscore/category)