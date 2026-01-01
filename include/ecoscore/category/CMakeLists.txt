# Collect source files
file(GLOB_RECURSE CATEGORY_SOURCES "src/*.cpp")
file(GLOB_RECURSE CATEGORY_HEADERS "include/category/*.h")

add_library(category STATIC ${CATEGORY_SOURCES} ${CATEGORY_HEADERS})

target_include_directories(category PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Optional: Precompiled headers if you have one, e.g., include/category/PCH.h
# target_precompile_headers(category PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/category/PCH.h)
