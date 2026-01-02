function(add_smoke_test_for_headers project)
    set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include/ecoscore/${project})
    message(${HEADER_DIR})
    file(GLOB_RECURSE HEADER_FILES RELATIVE ${CMAKE_SOURCE_DIR}/include/ ${HEADER_DIR}/*.h)

    # Create a temporary directory for generated test files
    set(smoke_test_dir "${CMAKE_CURRENT_BINARY_DIR}/smoke_tests")
    file(MAKE_DIRECTORY "${smoke_test_dir}")    

    set(test_file tools/artifacts/smoke_test_${project}.cpp)
    file(REMOVE ${test_file})
    file(APPEND ${test_file} "#include <iostream>\n")

    # Loop through each header file
    foreach(HEADER_FILE IN LISTS HEADER_FILES)
        # Get the filename only (without path)
        message(${HEADER_FILE})
        get_filename_component(HEADER_NAME ${HEADER_FILE} NAME)
        set(header_include ${HEADER_FILE})
        file(APPEND ${test_file} "#include \"${header_include}\"\n")
    endforeach()

    file(APPEND ${test_file} "int main() { std::cout << \"Success.\"; return 0; }\n")

    add_executable(${project}.smoke_tests ${test_file})
    target_link_libraries(${project}.smoke_tests ${project})

endfunction()
