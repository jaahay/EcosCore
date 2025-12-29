# src/ecoscore/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_subdirectory(meta)
add_subdirectory(tag)
add_subdirectory(type)
add_subdirectory(priority)
add_subdirectory(language)

add_library(ecoscore INTERFACE)

target_link_libraries(ecoscore INTERFACE
    ecoscore.meta
    ecoscore.tag
    ecoscore.type
    ecoscore.priority
    ecoscore.language
)

target_include_directories(ecoscore INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore INTERFACE cxx_std_20)
