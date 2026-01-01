# /src/ecoscore/category/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.category STATIC)

# Define all module interface files in a single variable
set(MODULE_FILES
    Category.ixx
    Member.ixx
    
    Categories.ixx

    Flow.ixx
    flow/Continue.ixx
    #flow/translations/Continue.ixx
    flow/Stop.ixx

    Phase.ixx
    phase/After.ixx
    phase/Before.ixx
    phase/End.ixx
    phase/Error.ixx
    phase/Finalize.ixx
    phase/Main.ixx
    phase/Process.ixx
    phase/Start.ixx

    Outcome.ixx
    outcome/Fail.ixx
    outcome/Partial.ixx
    outcome/Pass.ixx
)

target_sources(ecoscore.category PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES ${MODULE_FILES}
)

target_include_directories(ecoscore.category PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.category PUBLIC cxx_std_23)

target_compile_options(ecoscore.category PRIVATE
    /W4 /WX
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest /permissive->
)

set_target_properties(ecoscore.category PROPERTIES
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