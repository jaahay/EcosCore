import os
import re
import shutil

def generate_include_guard(relative_path):
    guard = re.sub(r'[^A-Za-z0-9]', '_', relative_path).upper()
    return f"__{guard}__"

def convert_import_to_include(line):
    m = re.match(r'^\s*(export\s+)?import\s+([\w\.]+);', line)
    if m:
        module_name = m.group(2)
        include_path = module_name.replace('.', '/') + '.h'
        return f'#include "{include_path}"\n'
    return None

def process_file(full_path, root_dir, include_root):
    rel_path = os.path.relpath(full_path, root_dir)
    guard = generate_include_guard(rel_path)

    with open(full_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    new_lines = []
    inside_guard = False

    for line in lines:
        if re.match(r'^\s*export\s+module\s+.+;\s*$', line):
            new_lines.append(f"#ifndef {guard}\n")
            new_lines.append(f"#define {guard}\n")
            inside_guard = True
            continue

        inc_line = convert_import_to_include(line)
        if inc_line is not None:
            new_lines.append(inc_line)
            continue

        line = re.sub(r'^\s*export\s+', '', line)
        new_lines.append(line)

    if inside_guard:
        new_lines.append(f"#endif // {guard}\n")

    # Determine new file path under include/
    # Replace src/ prefix with include/
    if rel_path.startswith('src' + os.sep):
        rel_path_under_include = os.path.join('include', rel_path[len('src'+os.sep):])
    else:
        rel_path_under_include = os.path.join('include', rel_path)

    new_file_path = os.path.splitext(os.path.join(root_dir, rel_path_under_include))[0] + '.h'

    os.makedirs(os.path.dirname(new_file_path), exist_ok=True)

    with open(new_file_path, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)

    print(f"Converted: {rel_path} -> {os.path.relpath(new_file_path, root_dir)}")

    # Uncomment to delete original .ixx file
    # os.remove(full_path)

def main():
    root_dir = os.getcwd()
    include_root = os.path.join(root_dir, 'include')

    print(f"Starting conversion from 'src/' to 'include/' in root: {root_dir}")

    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.ixx'):
                full_path = os.path.join(dirpath, filename)
                process_file(full_path, root_dir, include_root)

    print("Conversion complete.")

if __name__ == "__main__":
    main()
