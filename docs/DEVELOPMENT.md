# Development Guide

This guide provides comprehensive instructions for setting up the development environment, building projects, and understanding the codebase structure.

## Table of Contents

- [Development Environment Setup](#development-environment-setup)
- [Building Projects](#building-projects)
- [Project Structure](#project-structure)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Common Issues](#common-issues)

## Development Environment Setup

### Prerequisites

#### Required
- **C++ Compiler**: One of the following:
  - **Windows**: MinGW-w64 (GCC for Windows) or MSVC (Visual Studio)
  - **Linux**: GCC (`sudo apt install g++` on Ubuntu/Debian)
  - **macOS**: Clang (comes with Xcode Command Line Tools)

#### Recommended IDEs
- **Visual Studio 2022** (Windows) - Full IDE with debugging support
- **Visual Studio Code** (Cross-platform) - Lightweight with C++ extensions
- **Code::Blocks** (Cross-platform) - Alternative lightweight IDE

### Windows Setup (Recommended for this Repository)

#### Option 1: Visual Studio (MSVC)

1. **Download Visual Studio 2022 Community** (free)
   - Visit: https://visualstudio.microsoft.com/downloads/

2. **During installation, select**:
   - Desktop development with C++
   - Windows 10/11 SDK

3. **Open a project**:
   ```
   Double-click any .sln file in project folders
   ```

#### Option 2: MinGW-w64 + VS Code

1. **Install MinGW-w64**:
   - Download from: https://www.mingw-w64.org/
   - Or use MSYS2: https://www.msys2.org/
   
   Using MSYS2 (recommended):
   ```bash
   # After installing MSYS2
   pacman -S mingw-w64-x86_64-gcc
   ```

2. **Add to PATH**:
   ```
   C:\msys64\mingw64\bin
   ```

3. **Install VS Code**:
   - Download from: https://code.visualstudio.com/

4. **Install C++ Extension**:
   - Open VS Code
   - Install "C/C++" extension by Microsoft

5. **Verify installation**:
   ```bash
   g++ --version
   ```
   Expected output: `g++ (GCC) X.X.X`

### Linux Setup

```bash
# Ubuntu/Debian
sudo apt update
sudo apt install g++ make git

# Fedora
sudo dnf install gcc-c++ make git

# Arch
sudo pacman -S gcc make git
```

### macOS Setup

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Verify
g++ --version
```

## Building Projects

### Method 1: Command Line (Universal)

Navigate to any project directory and compile:

```bash
# Example: Build P1
cd "P1 - Snowball Team Score Checker"
g++ -o snowball snowball_JCA.cpp
./snowball  # Linux/macOS
snowball.exe  # Windows
```

#### Common g++ Flags

```bash
# Debug build (recommended during development)
g++ -g -Wall -o program source.cpp

# Release build (optimized)
g++ -O2 -o program source.cpp

# C++11 standard
g++ -std=c++11 -o program source.cpp

# Multiple files (e.g., P7, P8)
g++ -o scooter Scooter.cpp "V1 Program 7.cpp"
g++ -o intlist IntList.cpp integers.cpp
```

### Method 2: Visual Studio

1. Open the `.sln` file (where available):
   - `P7 - Scooter/Program 7 - Scooter Objects/Program 7 - Scooter Objects.sln`
   - `P8 - IntList Linkedlist/IntList JCA/IntList JCA.sln`

2. Build:
   - **Build Solution**: `Ctrl+Shift+B`
   - **Run**: `F5` (debug) or `Ctrl+F5` (without debugging)

3. Output location:
   - Debug builds: `Debug/` folder
   - Release builds: `Release/` folder

### Method 3: VS Code Tasks

The repository includes pre-configured build tasks in `.vscode/tasks.json`.

**To build**:
1. Open a C++ file
2. Press `Ctrl+Shift+B` (Windows/Linux) or `Cmd+Shift+B` (macOS)
3. Select "C/C++: g++.exe build active file"

**Note**: The current `tasks.json` is Windows-specific. For Linux/macOS, update the compiler path:

```json
{
    "command": "/usr/bin/g++",  // Linux/macOS
    "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
    ]
}
```

## Project Structure

### Single-File Projects

Most projects (P1-P6) are single-file programs:

```
P1 - Snowball Team Score Checker/
├── snowball_JCA.cpp    # Main source
├── snowball.txt        # Data file (required for execution)
└── snowball_JCA.exe    # Compiled output
```

**Build**:
```bash
cd "P1 - Snowball Team Score Checker"
g++ snowball_JCA.cpp -o snowball_JCA
```

### Multi-File Projects (P7, P8)

Projects with header files and multiple source files:

```
P7 - Scooter/Program 7 - Scooter Objects/
├── Scooter.h           # Class declaration
├── Scooter.cpp         # Class implementation
└── V1 Program 7.cpp    # Main driver
```

**Build**:
```bash
cd "P7 - Scooter/Program 7 - Scooter Objects"
g++ Scooter.cpp "V1 Program 7.cpp" -o scooter
```

```
P8 - IntList Linkedlist/IntList JCA/
├── IntList.h           # Class declaration
├── IntList.cpp         # Class implementation
└── integers.cpp        # Main driver
```

**Build**:
```bash
cd "P8 - IntList Linkedlist/IntList JCA"
g++ IntList.cpp integers.cpp -o intlist
```

## Development Workflow

### 1. Choose a Project

```bash
git clone https://github.com/jakujobi/CSC-250-with-Cpp.git
cd CSC-250-with-Cpp
```

### 2. Navigate to Project

```bash
cd "P7 - Scooter/Program 7 - Scooter Objects"
```

### 3. Review Requirements

- Check `Requirements & Design/` folder for specifications
- Read inline comments in source files
- Review design documents (`.docx` files)

### 4. Build

```bash
g++ Scooter.cpp "V1 Program 7.cpp" -o scooter
```

### 5. Run

```bash
./scooter  # Linux/macOS
scooter.exe  # Windows
```

### 6. Test

- Follow on-screen prompts
- Verify output matches expected behavior
- Test edge cases

## Coding Standards

Based on observed patterns in the codebase:

### Naming Conventions

```cpp
// Functions: camelCase
void printWelcome();
int getUserChoice();

// Variables: camelCase or descriptive names
int userChoice;
int teamID;
double currentSpeed;

// Constants: UPPER_CASE (when used)
const int MAX_TEAMS = 50;
const double TAX_RATE = 0.065;

// Classes: PascalCase
class Scooter;
class IntList;

// Private members: camelCase (sometimes with prefix)
private:
    string type;
    float max_speed;
```

### File Organization

```cpp
// 1. Header comment block
/*
Program Name
Description
Author: John Akujobi
Date: MM/DD/YYYY
Class: CSC 250
*/

// 2. Includes
#include <iostream>
#include <fstream>

// 3. Using statements
using namespace std;

// 4. Constants
const int MAX_SIZE = 50;

// 5. Function prototypes
void functionName();

// 6. Main function
int main() {
    // Implementation
    return 0;
}

// 7. Function definitions
void functionName() {
    // Implementation
}
```

### Comments

```cpp
// Single-line comments for brief explanations
int count = 0;  // Initialize counter

/* Multi-line comments for:
   - Program headers
   - Requirements
   - Complex logic explanations
*/
```

## Testing Projects

### Manual Testing

Each project includes test data files:

```bash
# P1 - Snowball
# Uses snowball.txt
# Test: Enter team ID 182, expect hits and times hit data

# P5 - Shirts
# Uses shirts.txt
# Test: Order items, checkout, verify tax calculation

# P6 - Feed Inventory
# Uses feed.dat (binary)
# Test: CRUD operations on inventory
```

### Creating Test Data

Example for P1 (`snowball.txt`):
```
182 37 12
837 14 25
374 29 28
```

Format: `TeamID Hits TimesHit`

### Validation Checklist

For each project:
- [ ] Compiles without errors
- [ ] Compiles without warnings (with `-Wall`)
- [ ] Runs without crashes
- [ ] Handles invalid input gracefully
- [ ] Produces expected output
- [ ] Memory is properly managed (no leaks in P7/P8)

## Common Issues

### Issue: "g++ not found" or "command not found"

**Solution**:
- Ensure g++ is installed
- Check PATH environment variable
- Restart terminal/IDE after installation

### Issue: Cannot open data file

**Solution**:
- Ensure data file (e.g., `snowball.txt`) is in the same directory as the executable
- Check file name case (case-sensitive on Linux/macOS)
- Verify file permissions

### Issue: Linking errors with multi-file projects

**Solution**:
- Include all `.cpp` files in compile command:
  ```bash
  g++ file1.cpp file2.cpp -o program
  ```
- Do NOT compile `.h` files directly

### Issue: "undefined reference to WinMain"

**Cause**: Missing or incorrect `main()` function

**Solution**:
```cpp
int main() {  // Not WinMain
    return 0;
}
```

### Issue: Windows path spaces

**Solution**: Use quotes around paths with spaces:
```bash
cd "P1 - Snowball Team Score Checker"
g++ "snowball_JCA.cpp" -o snowball
```

### Issue: Line ending differences (Windows vs Unix)

**Symptoms**: Compilation errors like "unexpected token" or file not found

**Solution**:
```bash
# Convert Windows (CRLF) to Unix (LF)
dos2unix filename.cpp

# Or in VS Code: Click "CRLF" in status bar → Select "LF"
```

## Build Automation (Optional)

### Using Make (Linux/macOS)

Create a `Makefile` in project directory:

```makefile
# Example for P7
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

scooter: Scooter.cpp V1\ Program\ 7.cpp Scooter.h
	$(CXX) $(CXXFLAGS) Scooter.cpp V1\ Program\ 7.cpp -o scooter

clean:
	rm -f scooter

.PHONY: clean
```

**Usage**:
```bash
make
make clean
```

### Using CMake (Cross-platform)

Create `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(ScooterProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(scooter
    Scooter.cpp
    "V1 Program 7.cpp"
)
```

**Usage**:
```bash
mkdir build
cd build
cmake ..
make
```

## Debugging

### Using GDB (Linux/macOS)

```bash
# Compile with debug symbols
g++ -g program.cpp -o program

# Run debugger
gdb ./program

# GDB commands
(gdb) break main       # Set breakpoint
(gdb) run             # Start execution
(gdb) next            # Next line
(gdb) print variable  # Print value
(gdb) quit            # Exit
```

### Using Visual Studio Debugger

1. Set breakpoint: Click left margin of line
2. Start debugging: `F5`
3. Step over: `F10`
4. Step into: `F11`
5. Continue: `F5`

### Using VS Code Debugger

1. Install "C/C++" extension
2. Create `.vscode/launch.json`
3. Set breakpoints
4. Press `F5` to start debugging

## Performance Considerations

### Project-Specific Notes

**P1 - Binary Search**:
- Time complexity: O(log n) for search
- Requires sorted array

**P2 - 2D Arrays**:
- Fixed size: 5×4
- Row-major storage

**P8 - Linked List**:
- Insertion at sorted position: O(n)
- Recursive counting: O(n)

## Additional Resources

### Learning Resources
- [cplusplus.com](https://www.cplusplus.com/) - C++ reference
- [cppreference.com](https://en.cppreference.com/) - Detailed C++ documentation
- [LearnCpp.com](https://www.learncpp.com/) - C++ tutorials

### Tools
- [Compiler Explorer](https://godbolt.org/) - See compiled assembly online
- [OnlineGDB](https://www.onlinegdb.com/) - Online C++ compiler and debugger
- [C++ Insights](https://cppinsights.io/) - See what the compiler does

---

For architecture details, see [ARCHITECTURE.md](./ARCHITECTURE.md).
For main project overview, see [README.md](../README.md).
