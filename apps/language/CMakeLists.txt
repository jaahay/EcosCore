add_executable(language_app main.cpp)

file(GLOB_RECURSE LANGUAGE_HEADERS
    ${CMAKE_SOURCE_DIR}/include/ecoscore/language/*.h
)

target_sources(language_app PRIVATE ${LANGUAGE_HEADERS})

target_link_libraries(language_app PRIVATE language)
