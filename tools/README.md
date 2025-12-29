# Tools Directory

This directory contains helper scripts and utilities to support project development and maintenance.

## generate_file_lists.py

This script generates file listings of the main source directories and root-level files, producing comprehensive snapshots of the project structure.

### What it does

- Recursively lists files under the following directories:
  - `include/`
  - `src/`
  - `tests/`
  - `examples/`
- Lists root-level files including:
  - `.gitignore`
  - `CMakeLists.txt`
  - `LICENSE`
  - All Markdown files (`*.md`)
- Skips hidden directories (those starting with `.`) and directories named `out`.
- Outputs files are saved in `tools/generated/` with the `.generated.txt` suffix.

### Generated files

- `include_tree.generated.txt`
- `src_tree.generated.txt`
- `tests_tree.generated.txt`
- `examples_tree.generated.txt`
- `root_files.generated.txt`

### Usage

Run the script from your project root:

```bash
python tools/generate_file_lists.py
```

Make sure you have Python 3 installed.

### Version Control

- The `tools/generated/` directory is **excluded** from version control via `.gitignore` to avoid committing generated files.
- Regenerate listings as needed during development or before releases.

---

Feel free to extend or modify the scripts here to suit your project’s evolving needs.
