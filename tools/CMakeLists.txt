function(add_smoke_test_for_headers proj dir)
    # Ensure the directory path is absolute or relative to the current source directory
    get_filename_component(dir_abs "${dir}" ABSOLUTE BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

    # Scan for all header files recursively in the given directory
    file(GLOB_RECURSE header_files
        RELATIVE "${dir_abs}"
        "${dir_abs}/*.h" "${dir_abs}/*.hpp" "${dir_abs}/*.hh" "${dir_abs}/*.hxx"
    )

    if(NOT header_files)
        message(WARNING "No header files found in directory: ${dir_abs}")
        return()
    endif()

    # Create a temporary directory for generated test files
    set(smoke_test_dir "${CMAKE_CURRENT_BINARY_DIR}/smoke_tests")
    file(MAKE_DIRECTORY "${smoke_test_dir}")

    # List to collect all smoke test executables
    set(smoke_targets)

    foreach(header IN LISTS header_files)
        # Replace directory separators with underscores for target name
        string(REPLACE "/" "_" header_safe "${header}")
        string(REPLACE "." "_" header_safe "${header_safe}")

        # Name of the smoke test executable for this header
        set(target_name "smoke_test_${header_safe}")

        # Full path to the header file
        set(header_path "${dir_abs}/${header}")

        # Generate a minimal source file that includes the header
        set(test_source "${smoke_test_dir}/${header_safe}_test.cpp")
        file(WRITE "${test_source}" "#include \"${header_path}\"\nint main() { return 0; }\n")

        # Add executable target
        add_executable(${target_name} "${test_source}")

        # Include the directory containing the header, so that #include "" works
        get_filename_component(header_dir "${header_path}" DIRECTORY)
        target_include_directories(${target_name} PRIVATE "${header_dir}")

        # Optionally, you can propagate compile options or link libraries here if needed
        # target_compile_options(${target_name} PRIVATE ...)
        # target_link_libraries(${target_name} PRIVATE ...)

        list(APPEND smoke_targets ${target_name})
    endforeach()

    # Optionally create a custom target to build all smoke tests at once
    add_custom_target(${proj}.smoke_tests ALL DEPENDS ${smoke_targets})

endfunction()
