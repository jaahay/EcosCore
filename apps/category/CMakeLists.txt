add_executable(category_app main.cpp)

file(GLOB_RECURSE CATEGORY_HEADERS
    ${CMAKE_SOURCE_DIR}/include/ecoscore/category/*.h
)

target_sources(category_app PRIVATE ${CATEGORY_HEADERS})

target_link_libraries(category_app PRIVATE category)
