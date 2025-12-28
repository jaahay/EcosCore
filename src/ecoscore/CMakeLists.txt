# src/ecoscore/CMakeLists.txt
add_subdirectory(priority)

add_library(ecoscore INTERFACE)

target_link_libraries(ecoscore INTERFACE
    ecoscore.meta
    ecoscore.type
    ecoscore.tag
    ecoscore.priority
)

target_include_directories(ecoscore INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_compile_features(ecoscore INTERFACE cxx_std_20)
