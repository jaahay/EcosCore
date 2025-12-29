# src/ecoscore/type/CMakeLists.txt
add_library(ecoscore.type.impl STATIC)

target_sources(ecoscore.type.impl PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        StructType.ixx
        TemplateType.ixx
        Concepts.ixx
)

target_include_directories(ecoscore.type.impl PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(ecoscore.type.impl PUBLIC cxx_std_20)

add_library(ecoscore.type STATIC)

target_sources(ecoscore.type PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Type.ixx
)

target_include_directories(ecoscore.type PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(ecoscore.type PUBLIC cxx_std_20)

target_link_libraries(ecoscore.type PUBLIC ecoscore.type.impl)
