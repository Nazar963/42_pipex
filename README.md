# Pipex 🔄

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_pipex)](https://github.com/Nazar963/42_pipex/blob/master/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_pipex/.github/workflows/build.yml?branch=main)](https://github.com/Nazar963/42_pipex/.github/workflows/build.yml)

A UNIX pipe implementation handling multiple commands with input/output redirection, supporting both single and multiple pipe operations.

## Table of Contents 📖
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Makefile Targets](#makefile-targets)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Description
This 42 School project recreates shell pipe functionality (`|`), handling:
- Input/output file redirection
- Multiple command execution
- Environment path resolution
- Error handling with clean exit codes

## Features

### Core Functionality 🔧
- Basic pipe operations: `./pipex file1 cmd1 cmd2 file2`
- Error handling for:
  - Invalid permissions
  - Command not found
  - File access issues
- PATH environment variable resolution
- File descriptor management

## Installation

### Requirements
- GCC (GNU Compiler Collection)
- GNU Make
- UNIX-like system

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/Nazar963/42_pipex.git
   cd 42_pipex
   ```
2. Build the project:
   ```bash
   make
   ```
3. Executable `pipex` will be created

## Usage

### Basic Syntax
```bash
./pipex infile "cmd1" "cmd2" outfile
```

### Example
```bash
# Compare with shell: < input.txt grep '42' | wc -l > output.txt
./pipex input.txt "grep 42" "wc -l" output.txt
```

## Makefile Targets
- `make` : Compile mandatory version
- `make clean` : Remove object files
- `make fclean` : Remove objects and executable
- `make re` : Rebuild project

## Testing
Validate with:
- [Yoo0lh/pipex_tester_42](https://github.com/Yoo0lh/pipex_tester_42)
- [vfurmane/pipex-tester](https://github.com/vfurmane/pipex-tester#readme)
- [denisgodoy/pipex-tester](https://github.com/denisgodoy/pipex-tester)
- Custom test cases:
  ```bash
  # Test error handling
  ./pipex nofile invalidcmd anothercmd output
  
  # Memory check
  valgrind --leak-check=full ./pipex infile ls wc outfile
  ```

## Acknowledgments
- 42 School curriculum
- UNIX pipe documentation
- Peer code reviews
- Open source testing tools
  
## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the test suite or adding more test cases.

## License
Distributed under the MIT License - see [LICENSE](LICENSE) for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

---

⭐ **Star this repository if you found it helpful!**  
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_pipex?style=social)](https://github.com/Nazar963/42_pipex/stargazers)

[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)

---
Good luck with your Pipex project at 42! 🚀
