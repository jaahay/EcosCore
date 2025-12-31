# /src/ecoscore/state/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.state STATIC)

target_sources(ecoscore.state PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Detail.ixx

        Category.ixx
        Flows.ixx
        Outcomes.ixx
        Phases.ixx
        Tag.ixx

        flow/Continue.ixx
        flow/Stop.ixx

        phase/After.ixx
        phase/Before.ixx
        phase/End.ixx
        phase/Error.ixx
        phase/Finalize.ixx
        phase/Main.ixx
        phase/Process.ixx
        phase/Start.ixx

        outcome/Fail.ixx
        outcome/Partial.ixx
        outcome/Pass.ixx
)

target_include_directories(ecoscore.state PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.state PUBLIC cxx_std_23)

target_compile_options(ecoscore.state PRIVATE
    /W4 /WX
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest /permissive->
)

set_target_properties(ecoscore.state PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_MODULE_STD 1
)
