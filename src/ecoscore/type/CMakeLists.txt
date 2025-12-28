# src/ecoscore/type/CMakeLists.txt
add_library(ecoscore_type_StructType MODULE StructType.ixx)
add_library(ecoscore_type_TemplateType MODULE TemplateType.ixx)
add_library(ecoscore_type_Concepts MODULE Concepts.ixx)

add_library(ecoscore_type INTERFACE)
target_link_libraries(ecoscore_type INTERFACE
    ecoscore_type_StructType
    ecoscore_type_TemplateType
    ecoscore_type_Concepts
)
target_include_directories(ecoscore_type INTERFACE ${CMAKE_SOURCE_DIR}/include)
