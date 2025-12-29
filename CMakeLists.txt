# EcosCore/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subdirectory for the ecoscore library source
add_subdirectory(src/ecoscore)

# Optionally add tests and examples directories here
# add_subdirectory(tests)
# add_subdirectory(examples)
