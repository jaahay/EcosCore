import os
import re

def generate_include_guard(relative_path):
    # Uppercase, replace non-alphanumeric with underscore
    guard = re.sub(r'[^A-Za-z0-9]', '_', relative_path).upper()
    return f"ECOSCORE_{guard}"

def ensure_file_comment(lines, relative_path):
    file_comment = f"// File: {relative_path.replace(os.sep, '/')}\n"
    if not lines or not lines[0].startswith("// File:"):
        lines.insert(0, file_comment)
    else:
        # Replace existing file comment if different
        if lines[0].strip() != file_comment.strip():
            lines[0] = file_comment
    return lines

def ensure_include_guard(lines, guard):
    # Find ifndef and define lines
    ifndef_index = -1
    define_index = -1
    endif_index = -1

    for i, line in enumerate(lines):
        if ifndef_index == -1 and re.match(r'#ifndef\s+\w+', line):
            ifndef_index = i
        elif define_index == -1 and re.match(r'#define\s+\w+', line):
            define_index = i
        elif line.strip().startswith("#endif"):
            endif_index = i

    # Insert ifndef and define if missing or incorrect
    if ifndef_index == -1 or define_index == -1:
        # Insert after file comment (assumed line 0)
        lines.insert(1, f"#ifndef {guard}\n")
        lines.insert(2, f"#define {guard}\n")
        # Insert #endif at end
        lines.append(f"#endif // {guard}\n")
    else:
        # Fix guards if names differ
        ifndef_name = lines[ifndef_index].strip().split()[1]
        define_name = lines[define_index].strip().split()[1]
        if ifndef_name != guard:
            lines[ifndef_index] = f"#ifndef {guard}\n"
        if define_name != guard:
            lines[define_index] = f"#define {guard}\n"
        # Fix endif comment if present
        if endif_index != -1:
            endif_line = lines[endif_index].strip()
            if '//' in endif_line:
                lines[endif_index] = f"#endif // {guard}\n"
            else:
                lines[endif_index] = f"#endif // {guard}\n"
        else:
            # Add endif at end if missing
            lines.append(f"#endif // {guard}\n")

    return lines

def fix_namespace_comments(lines):
    namespace_stack = []
    new_lines = []
    ns_open_re = re.compile(r'^\s*namespace\s+([\w:]+)\s*{')
    ns_close_re = re.compile(r'^\s*}\s*(//.*)?$')

    for line in lines:
        open_match = ns_open_re.match(line)
        close_match = ns_close_re.match(line)

        if open_match:
            ns_name = open_match.group(1)
            namespace_stack.append(ns_name)
            new_lines.append(line)
        elif close_match:
            if namespace_stack:
                ns_name = namespace_stack.pop()
                # Add namespace comment after closing brace
                new_lines.append(f"}} // namespace {ns_name}\n")
            else:
                # No namespace to close, just append
                new_lines.append(line)
        else:
            new_lines.append(line)

    return new_lines

def process_file(full_path, root_dir):
    rel_path = os.path.relpath(full_path, root_dir)
    guard = generate_include_guard(rel_path)

    with open(full_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    lines = ensure_file_comment(lines, rel_path)
    lines = ensure_include_guard(lines, guard)
    lines = fix_namespace_comments(lines)

    with open(full_path, 'w', encoding='utf-8') as f:
        f.writelines(lines)

    print(f"Processed {rel_path}")

def main():
    root_dir = os.path.join(os.getcwd(), "include")
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.h'):
                full_path = os.path.join(dirpath, filename)
                process_file(full_path, root_dir)
    print("All headers processed.")

if __name__ == "__main__":
    main()
