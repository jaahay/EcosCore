# src/ecoscore/meta/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

project(ecoscore.meta LANGUAGES CXX)

add_library(ecoscore.meta STATIC)

# Define module interface files once
set(MODULE_FILES
    
    
    
    
    
)


target_sources(ecoscore.meta PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES ${MODULE_FILES}
)

target_include_directories(ecoscore.meta PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.meta PUBLIC cxx_std_23)

target_compile_options(ecoscore.meta PRIVATE
    /W4 /WX
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest /permissive->
)

set_target_properties(ecoscore.meta PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_MODULE_STD 1
)

source_group(
    TREE ${CMAKE_SOURCE_DIR}/src/ecoscore
    PREFIX "Source Files"
    FILES ${MODULE_FILES}
)
