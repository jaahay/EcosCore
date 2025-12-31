# /src/ecoscore/meta/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.meta STATIC)

target_sources(ecoscore.meta PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        CycleCheck.ixx
        Meta.ixx
        Tuple.ixx
        TypeList.ixx
        Variant.ixx
)

target_include_directories(ecoscore.meta PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.meta PUBLIC cxx_std_20)

target_compile_options(ecoscore.meta PRIVATE /W4 /WX)
