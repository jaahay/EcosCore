# src/ecoscore/meta/CMakeLists.txt
add_library(ecoscore.meta STATIC)

target_sources(ecoscore.meta PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Meta.ixx
        CycleCheck.ixx
        Tuple.ixx
        TypeList.ixx
        Variant.ixx
)

target_include_directories(ecoscore.meta PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.meta PUBLIC cxx_std_20)
