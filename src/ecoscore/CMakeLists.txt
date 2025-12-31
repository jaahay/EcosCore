# /src/ecoscore/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

# -----------------------------------------------------------------------------
# @brief EcosCore core library build configuration.
# Organizes submodules: language, localization, meta, priority, tag, type.
# Defines aggregate INTERFACE library ecoscore for easy consumption.
# -----------------------------------------------------------------------------

# Add submodules in alphabetical order
add_subdirectory(language)
#add_subdirectory(localization)
add_subdirectory(meta)
#add_subdirectory(priority)
add_subdirectory(tag)

# Aggregate interface library for EcosCore
add_library(ecoscore INTERFACE)

# Include root include directory transitively for all consumers
target_include_directories(ecoscore INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

# Link all component libraries transitively
target_link_libraries(ecoscore INTERFACE
    ecoscore.language
    #ecoscore.localization
    ecoscore.meta
    #ecoscore.priority
    ecoscore.tag
)

# Enforce C++20 for consumers of ecoscore
target_compile_features(ecoscore INTERFACE cxx_std_20)

# Enable strict warnings for all component libraries (MSVC example)
foreach(lib IN ITEMS ecoscore.language ecoscore.localization ecoscore.meta ecoscore.priority ecoscore.tag ecoscore.type)
#    target_compile_options(${lib} PRIVATE /W4 /WX)
endforeach()
