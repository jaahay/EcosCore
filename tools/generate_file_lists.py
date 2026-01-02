import os
import sys
import subprocess
from pathlib import Path

# Configurable paths relative to script location
BASE_DIR = Path(__file__).resolve().parent.parent  # Assuming script in EcosCore/tools/
INCLUDE_DIR = BASE_DIR / "include" / "ecoscore" / "Lib"
SRC_DIR = BASE_DIR / "src" / "Lib"
BUILD_DIR = BASE_DIR / "tools" / "build_test"

def find_headers(lib_name):
    lib_include_dir = INCLUDE_DIR / lib_name
    if not lib_include_dir.exists():
        print(f"Error: Include directory for library '{lib_name}' does not exist: {lib_include_dir}")
        sys.exit(1)
    headers = list(lib_include_dir.rglob("*.h")) + list(lib_include_dir.rglob("*.hpp"))
    return headers

def find_sources(lib_name):
    lib_src_dir = SRC_DIR / lib_name
    if not lib_src_dir.exists():
        print(f"Warning: Source directory for library '{lib_name}' does not exist: {lib_src_dir}")
        return []
    sources = list(lib_src_dir.rglob("*.cpp"))
    return sources

def generate_main_cpp(headers, output_path):
    includes = []
    for header in headers:
        # Create relative path from INCLUDE_DIR to header for #include
        rel_path = header.relative_to(BASE_DIR / "include")
        includes.append(f'#include "{rel_path.as_posix()}"')
    content = "\n".join(includes) + "\n\nint main() { return 0; }"
    with open(output_path, "w") as f:
        f.write(content)

def compile_code(lib_name, main_cpp_path, sources):
    # Prepare build directory
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    # Compiler and flags - adjust as needed
    compiler = "g++"
    cxx_flags = ["-std=c++17", "-I" + str(BASE_DIR / "include")]
    # Add include path for the library headers
    cxx_flags.append("-I" + str(INCLUDE_DIR / lib_name))
    # Output executable path
    output_exe = BUILD_DIR / f"test_{lib_name}"
    # Source files to compile (main.cpp + lib sources)
    source_files = [str(main_cpp_path)] + [str(src) for src in sources]
    cmd = [compiler] + cxx_flags + source_files + ["-o", str(output_exe)]
    print("Compiling with command:")
    print(" ".join(cmd))
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("Compilation failed with errors:")
        print(result.stderr)
        return False
    print(f"Compilation succeeded. Executable created at {output_exe}")
    return True

def clean_up(main_cpp_path):
    try:
        main_cpp_path.unlink()
        # Optionally remove executable and build directory if empty
        for item in BUILD_DIR.iterdir():
            if item.is_file():
                item.unlink()
        BUILD_DIR.rmdir()
    except Exception as e:
        print(f"Cleanup warning: {e}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python test_lib.py <LibraryName>")
        sys.exit(1)
    lib_name = sys.argv[1]
    headers = find_headers(lib_name)
    if not headers:
        print(f"No headers found for library '{lib_name}'.")
        sys.exit(1)
    sources = find_sources(lib_name)
    main_cpp_path = BUILD_DIR / "main.cpp"
    generate_main_cpp(headers, main_cpp_path)
    success = compile_code(lib_name, main_cpp_path, sources)
    clean_up(main_cpp_path)
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
