cmake_minimum_required(VERSION 3.28)
project(EcosCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the meta domain header-only library
add_subdirectory(src/meta)

# Add the executable app that uses the meta domain
add_subdirectory(apps/meta)