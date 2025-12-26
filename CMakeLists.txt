cmake_minimum_required(VERSION 3.15)
project(EcosCore LANGUAGES CXX)

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define header-only library target
add_library(EcosCore INTERFACE)

# Include directories for consumers
target_include_directories(EcosCore INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Optional: Glob headers for IDE grouping only
file(GLOB_RECURSE EcosCore_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore/*.h
)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore"
    PREFIX "Header Files"
    FILES ${EcosCore_HEADERS}
)

# Installation rules
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/EcosCore
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

install(TARGETS EcosCore EXPORT EcosCoreTargets)

install(EXPORT EcosCoreTargets
    FILE EcosCoreTargets.cmake
    NAMESPACE EcosCore::
    DESTINATION lib/cmake/EcosCore
)
