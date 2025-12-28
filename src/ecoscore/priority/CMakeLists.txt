# src/ecoscore/priority/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.priority INTERFACE)

target_sources(ecoscore.priority INTERFACE
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        VirtualPriorityOrdering.ixx
        StaticPriorityOrdering.ixx
        PriorityOrderingGraph.ixx
)

target_include_directories(ecoscore.priority INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_compile_features(ecoscore.priority INTERFACE cxx_std_20)
