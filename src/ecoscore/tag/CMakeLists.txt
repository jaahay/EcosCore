cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.tag INTERFACE)

target_sources(ecoscore.tag INTERFACE
    FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        Tag.ixx
        CharsetTags.ixx
        LanguageTags.ixx
        PhaseTags.ixx
        FlowTags.ixx
        OutcomeTags.ixx
)

target_include_directories(ecoscore.tag INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.tag INTERFACE cxx_std_20)
