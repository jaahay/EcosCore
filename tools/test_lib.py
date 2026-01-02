import os
import subprocess
import tempfile
import shutil

def generate_main_cpp(lib_name, include_path):
    headers = []
    for root, _, files in os.walk(include_path):
        for f in files:
            if f.endswith('.hpp') or f.endswith('.h'):
                rel_path = os.path.relpath(os.path.join(root, f), include_path)
                headers.append(rel_path.replace('\\', '/'))
    includes = '\n'.join([f'#include "{lib_name}/{header}"' for header in headers])
    main_cpp = f"""\
{includes}

int main() {{
    return 0;
}}
"""
    return main_cpp

def run_test(lib_name):
    base_path = os.path.abspath('EcosCore/include/ecoscore')
    include_path = os.path.join(base_path, lib_name)
    if not os.path.isdir(include_path):
        print(f"Library include path not found: {include_path}")
        return

    # Create temporary directory for build
    with tempfile.TemporaryDirectory() as temp_dir:
        main_cpp_path = os.path.join(temp_dir, 'main.cpp')
        with open(main_cpp_path, 'w') as f:
            f.write(generate_main_cpp(lib_name, base_path))

        # Create minimal CMakeLists.txt
        cmake_lists = f"""
cmake_minimum_required(VERSION 3.10)
project(Test{lib_name})

add_executable(test_{lib_name} main.cpp)
target_include_directories(test_{lib_name} PRIVATE {base_path})
"""
        cmake_lists_path = os.path.join(temp_dir, 'CMakeLists.txt')
        with open(cmake_lists_path, 'w') as f:
            f.write(cmake_lists)

        # Run cmake and build
        try:
            subprocess.check_call(['cmake', temp_dir, '-B', os.path.join(temp_dir, 'build')])
            subprocess.check_call(['cmake', '--build', os.path.join(temp_dir, 'build')])
            print(f"Library {lib_name} compiled successfully.")
        except subprocess.CalledProcessError as e:
            print(f"Compilation failed: {e}")

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print("Usage: python test_lib.py <library_name>")
    else:
        run_test(sys.argv[1])
