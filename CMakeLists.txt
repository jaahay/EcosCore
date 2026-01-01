cmake_minimum_required(VERSION 3.28)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# --- Fetch GoogleTest ---
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# Prevent GoogleTest from overriding your compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Header-only library ---
file(GLOB_RECURSE HEADERS
    "${PROJECT_SOURCE_DIR}/include/ecoscore/*.h"
    "${PROJECT_SOURCE_DIR}/include/ecoscore/*.hpp"
)

set(DUMMY_SOURCE "${PROJECT_SOURCE_DIR}/src/ecoscore/dummy.cpp")

add_library(headers STATIC ${HEADERS} ${DUMMY_SOURCE})

target_include_directories(headers PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Organize headers nicely in Visual Studio
source_group(TREE "${PROJECT_SOURCE_DIR}/include/ecoscore" PREFIX "headers" FILES ${HEADERS})
source_group("Sources" FILES ${DUMMY_SOURCE})

# --- Tests executable ---
file(GLOB_RECURSE TEST_SOURCES
    "${PROJECT_SOURCE_DIR}/tests/*.cpp"
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE headers gtest gtest_main)
target_include_directories(tests PRIVATE "${PROJECT_SOURCE_DIR}/include")
add_test(NAME AllTests COMMAND tests)

source_group(TREE "${PROJECT_SOURCE_DIR}/tests" PREFIX "tests" FILES ${TEST_SOURCES})

# --- Examples executable ---
file(GLOB_RECURSE EXAMPLE_SOURCES
    "${PROJECT_SOURCE_DIR}/examples/*.cpp"
)

add_executable(examples ${EXAMPLE_SOURCES})
target_link_libraries(examples PRIVATE headers)
target_include_directories(examples PRIVATE "${PROJECT_SOURCE_DIR}/include")

source_group(TREE "${PROJECT_SOURCE_DIR}/examples" PREFIX "examples" FILES ${EXAMPLE_SOURCES})
