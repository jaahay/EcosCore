cmake_minimum_required(VERSION 3.20)
project(EcosCore LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Core header-only interface target
add_library(EcosCore INTERFACE)
target_include_directories(EcosCore INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Event core module (header-only)
add_library(EcosCore_event_core INTERFACE)
target_include_directories(EcosCore_event_core INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/event/core
)
target_link_libraries(EcosCore_event_core INTERFACE EcosCore)
add_library(EcosCore::event-core ALIAS EcosCore_event_core)

# Event util module (header-only)
add_library(EcosCore_event_util INTERFACE)
target_include_directories(EcosCore_event_util INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/event/util
)
target_link_libraries(EcosCore_event_util INTERFACE EcosCore_event_core)
add_library(EcosCore::event-util ALIAS EcosCore_event_util)

# State module (header-only)
add_library(EcosCore_state INTERFACE)
target_include_directories(EcosCore_state INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/state
)
target_link_libraries(EcosCore_state INTERFACE EcosCore)
add_library(EcosCore::state ALIAS EcosCore_state)

# Concepts module (header-only)
add_library(EcosCore_concepts INTERFACE)
target_include_directories(EcosCore_concepts INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/concepts
)
target_link_libraries(EcosCore_concepts INTERFACE EcosCore)
add_library(EcosCore::concepts ALIAS EcosCore_concepts)

# Meta module (header-only)
add_library(EcosCore_meta INTERFACE)
target_include_directories(EcosCore_meta INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/meta
)
target_link_libraries(EcosCore_meta INTERFACE EcosCore)
add_library(EcosCore::meta ALIAS EcosCore_meta)

# Optional modules (metrics, serialization)
add_library(EcosCore_metrics INTERFACE)
target_include_directories(EcosCore_metrics INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/metrics
)
target_link_libraries(EcosCore_metrics INTERFACE EcosCore)
add_library(EcosCore::metrics ALIAS EcosCore_metrics)

add_library(EcosCore_serialization INTERFACE)
target_include_directories(EcosCore_serialization INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/serialization
)
target_link_libraries(EcosCore_serialization INTERFACE EcosCore)
add_library(EcosCore::serialization ALIAS EcosCore_serialization)

option(BUILD_TESTS "Build unit and integration tests" ON)

if(BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    enable_testing()

    #add_subdirectory(tests)
endif()

add_subdirectory(examples)