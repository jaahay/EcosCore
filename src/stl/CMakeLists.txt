# /src/stl/CMakeLists.txt

cmake_minimum_required(VERSION 3.28)

add_library(stl INTERFACE)

# List of STL headers to build as header units
set(STL_HEADERS
    string
    vector
    map
    unordered_map
    type_traits
    tuple
    iostream
    algorithm
    # Add more as needed
)

set(STL_HEADER_UNITS_DIR "${CMAKE_BINARY_DIR}/stl_header_units")

file(MAKE_DIRECTORY "${STL_HEADER_UNITS_DIR}")

set(STL_IFC_FILES)

foreach(header IN LISTS STL_HEADERS)
    set(ifc_file "${STL_HEADER_UNITS_DIR}/${header}.ifc")

    add_custom_command(
        OUTPUT "${ifc_file}"
        COMMAND
            cl /c /std:c++20 /experimental:module /headerUnit:${header} /Fo"${ifc_file}"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Building STL header unit: ${header}"
        VERBATIM
    )

    list(APPEND STL_IFC_FILES "${ifc_file}")
endforeach()

add_custom_target(build_stl_header_units ALL DEPENDS ${STL_IFC_FILES})

add_dependencies(stl build_stl_header_units)

target_compile_options(stl INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/ifcSearchDir${STL_HEADER_UNITS_DIR}>
)

target_include_directories(stl INTERFACE
    $<BUILD_INTERFACE:${STL_HEADER_UNITS_DIR}>
)
