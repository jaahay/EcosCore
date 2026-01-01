add_library(meta INTERFACE)

# Use absolute path to the include directory
target_include_directories(meta INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
