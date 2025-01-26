
# Pipex

## Introduction

Pipex is a project designed to explore the inner workings of UNIX pipes and process management. The objective is to replicate a simple shell behavior using pipes in C programming.

## Features

- Mimics the following shell behavior:
  ```bash
  < file1 cmd1 | cmd2 > file2
  ```
- Handles errors gracefully and ensures no memory leaks.
- Compatible with commands and file redirection.

## Usage

### Compilation

To compile the program, use the provided `Makefile`:
```bash
make
```

### Execution

Run the program with the following syntax:
```bash
./pipex file1 "cmd1" "cmd2" file2
```

### Examples

1. List directory contents and count the lines:
   ```bash
   ./pipex infile "ls -l" "wc -l" outfile
   ```
   Equivalent shell command:
   ```bash
   < infile ls -l | wc -l > outfile
   ```

2. Find occurrences of "a1" and count words:
   ```bash
   ./pipex infile "grep a1" "wc -w" outfile
   ```
   Equivalent shell command:
   ```bash
   < infile grep a1 | wc -w > outfile
   ```

## Requirements

- Ensure your project adheres to the following:
  - Use a `Makefile` for compilation with targets: `all`, `clean`, `fclean`, `re`.
  - Handle errors thoroughly (no segmentation faults, memory leaks, etc.).
  - Use only allowed functions, including `open`, `close`, `read`, `write`, `malloc`, `free`, and more.

- **Here Document**:
  Handle heredoc behavior:
  ```bash
  ./pipex here_doc LIMITER cmd cmd1 file
  ```
  Equivalent shell command:
  ```bash
  cmd << LIMITER | cmd1 >> file
  ```

## Testing

While tests are not graded, creating test cases for your implementation is highly recommended. This ensures your program works under various conditions.

## Submission Guidelines

Submit your project to the assigned Git repository. Only the contents of the repository will be evaluated. Ensure all files comply with naming conventions and that your `Makefile` correctly builds the project.
