# /CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

project(EcosCore LANGUAGES CXX)

# -----------------------------------------------------------------------------
# @brief Root CMake configuration for EcosCore project.
# Enforces C++20 standard and strict compiler warnings globally.
# Delegates build to src/ecoscore subdirectory.
# -----------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable strict compiler warnings globally
if(MSVC)
    add_compile_options(/W4 /WX)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU|AppleClang")
    add_compile_options(-Wall -Wextra -Werror)
endif()

# Add main EcosCore library source directory
add_subdirectory(src/ecoscore)

# Add tests and examples when available
# add_subdirectory(tests)
# add_subdirectory(examples)
