# src/ecoscore/priority/CMakeLists.txt
add_library(ecoscore.priority STATIC)

target_sources(ecoscore.priority PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Priority.ixx
        VirtualPriorityOrdering.ixx
        StaticPriorityOrdering.ixx
        PriorityOrderingGraph.ixx
        PriorityTags.ixx
)

target_include_directories(ecoscore.priority PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.priority PUBLIC cxx_std_20)
