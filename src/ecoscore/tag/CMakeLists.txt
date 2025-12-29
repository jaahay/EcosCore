# src/ecoscore/tag/CMakeLists.txt
add_library(ecoscore.tag STATIC)

target_sources(ecoscore.tag PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Tag.ixx
        PhaseTags.ixx
        FlowTags.ixx
        OutcomeTags.ixx
)

target_include_directories(ecoscore.tag PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.tag PUBLIC cxx_std_20)
