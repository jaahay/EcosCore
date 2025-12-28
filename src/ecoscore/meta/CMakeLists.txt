# src/ecoscore/meta/CMakeLists.txt
add_library(ecoscore_meta_TypeList MODULE TypeList.ixx)
add_library(ecoscore_meta_Tuple MODULE Tuple.ixx)
add_library(ecoscore_meta_Variant MODULE Variant.ixx)
add_library(ecoscore_meta_CycleCheck MODULE CycleCheck.ixx)

add_library(ecoscore_meta INTERFACE)
target_link_libraries(ecoscore_meta INTERFACE
    ecoscore_meta_TypeList
    ecoscore_meta_Tuple
    ecoscore_meta_Variant
    ecoscore_meta_CycleCheck
)
target_include_directories(ecoscore_meta INTERFACE ${CMAKE_SOURCE_DIR}/include)
