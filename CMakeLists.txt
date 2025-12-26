cmake_minimum_required(VERSION 3.15)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Glob headers relative to source directory for IDE grouping
file(GLOB_RECURSE EcosCore_HEADERS
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/*.h
)

# Create static library with dummy source file for IDE visibility
add_library(EcosCore STATIC src/dummy.cpp)

# Add headers to the target for IDE grouping (won't compile)
target_sources(EcosCore PRIVATE ${EcosCore_HEADERS})

target_include_directories(EcosCore PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Organize headers into IDE folders
source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${PROJECT_HEADERS}
)

# --- GoogleTest setup ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Unit tests ---

add_executable(CoreUnitTests tests/EcosCore/BasicUnitTest.cpp)

target_link_libraries(CoreUnitTests PRIVATE EcosCore gtest gtest_main)

add_test(NAME CoreUnitTests COMMAND CoreUnitTests)
