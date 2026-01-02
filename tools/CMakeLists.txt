function(add_smoke_test_for_headers LIBRARY)
    set(LIBRARY_INCLUDE_ROOT ${CMAKE_SOURCE_DIR}/include)
    set(LIBRARY_INCLUDE_DIR ${LIBRARY_INCLUDE_ROOT}/ecoscore/${LIBRARY})

    file(GLOB_RECURSE ABS_HEADERS
        ${LIBRARY_INCLUDE_DIR}/*.h
        ${LIBRARY_INCLUDE_DIR}/*.hpp
    )

    set(REL_HEADERS)

    foreach(ABS_HEADER IN LISTS ABS_HEADERS)
        file(RELATIVE_PATH REL_HEADER ${LIBRARY_INCLUDE_ROOT} ${ABS_HEADER})
        list(APPEND REL_HEADERS ${REL_HEADER})
    endforeach()

    set(test_file tools/artifacts/smoke_test_${LIBRARY}.cpp)
    file(REMOVE ${test_file})
    file(APPEND ${test_file} "#include <iostream>\n")

    # Loop through each header file
    foreach(HEADER_FILE IN LISTS REL_HEADERS)
        # Get the filename only (without path)
        message(${HEADER_FILE})
        file(APPEND ${test_file} "#include \"${HEADER_FILE}\"\n")
    endforeach()

    file(APPEND ${test_file} "int main() { std::cout << \"Success.\"; return 0; }\n")

    add_executable(${LIBRARY}.smoke_tests ${test_file})
    target_sources(${LIBRARY}.smoke_tests PRIVATE ${ABS_HEADERS})
    target_link_libraries(${LIBRARY}.smoke_tests ${LIBRARY})
endfunction()