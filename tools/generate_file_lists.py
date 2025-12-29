import os

# Directories to process
MAIN_DIRS = ['include', 'src', 'tests', 'examples']

# Root-level files to include (case-insensitive)
ROOT_FILES = ['.gitignore', 'cmakelists.txt', 'license']  # lowercase for matching

def list_files(base_path, output_file):
    with open(output_file, 'w', encoding='utf-8') as f:
        for root, dirs, files in os.walk(base_path):
            # Filter out hidden and 'out' directories
            dirs[:] = [d for d in dirs if not (d.startswith('.') or d == 'out')]

            for file in files:
                rel_dir = os.path.relpath(root, base_path)
                if rel_dir == '.':
                    rel_path = file
                else:
                    rel_path = os.path.join(rel_dir, file)
                # Use forward slashes for consistency
                f.write(rel_path.replace(os.sep, '/') + '\n')

def list_root_files(base_path, output_file):
    with open(output_file, 'w', encoding='utf-8') as f:
        for item in os.listdir(base_path):
            if os.path.isfile(os.path.join(base_path, item)):
                lower_item = item.lower()
                if lower_item in ROOT_FILES or lower_item.endswith('.md'):
                    f.write(item + '\n')

def main():
    project_root = os.getcwd()
    output_dir = os.path.join(project_root, "tools", "artifacts")
    os.makedirs(output_dir, exist_ok=True)

    # Process main directories
    for d in MAIN_DIRS:
        dir_path = os.path.join(project_root, d)
        if os.path.isdir(dir_path):
            out_file = os.path.join(output_dir, f"{d}_tree.generated.txt")
            list_files(dir_path, out_file)
            print(f"Wrote {out_file}")

    # Process root files
    root_out = os.path.join(output_dir, "root_files.generated.txt")
    list_root_files(project_root, root_out)
    print(f"Wrote {root_out}")

if __name__ == "__main__":
    main()
