add_executable(meta_app main.cpp)

file(GLOB_RECURSE META_HEADERS
    ${CMAKE_SOURCE_DIR}/include/ecoscore/meta/*.h
)

target_sources(meta_app PRIVATE ${META_HEADERS})

target_link_libraries(meta_app PRIVATE meta)
