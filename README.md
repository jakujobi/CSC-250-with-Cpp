# CSC 250 - C++ Programming Portfolio

A comprehensive collection of C++ programming assignments demonstrating fundamental to intermediate programming concepts, data structures, and object-oriented design principles. Created for CSC 250 course at South Dakota State University.

## 📋 Overview

This repository contains 8 major programming projects and additional practice exercises that showcase proficiency in C++, including file I/O, data structures, algorithm implementation, and object-oriented programming. Each project includes complete source code, design documentation, and requirements specifications.

## ✨ Key Features

- **Binary Search & Sorting Algorithms** - Implementation of search and sort algorithms with parallel arrays ([P1](./P1%20-%20Snowball%20Team%20Score%20Checker))
- **Object-Oriented Programming** - Classes with encapsulation, constructors, and member functions ([P7](./P7%20-%20Scooter), [P8](./P8%20-%20IntList%20Linkedlist))
- **Data Structures** - Custom linked list implementation with recursive operations ([P8](./P8%20-%20IntList%20Linkedlist))
- **File I/O Operations** - Reading from and writing to text and binary files ([P1](./P1%20-%20Snowball%20Team%20Score%20Checker), [P5](./P5%20-%20Structures%20Shirt%20Sales), [P6](./P6%20-%20Feed%20Inventory%20App))
- **Structures & Enums** - Complex data organization using C++ structures and enumerated types ([P5](./P5%20-%20Structures%20Shirt%20Sales))
- **2D Arrays** - Multi-dimensional array manipulation and table operations ([P2](./P2%20-%20Schedule%20Program%20for%20Winter%20at%20the%20State%20Park))
- **String Processing** - Both C-style and C++ string manipulation ([P4](./P4%20-%20Print%20Date%20Words%20from%20Date))
- **Modular Design** - Function decomposition and separation of concerns across all projects

## 🏗️ Architecture Overview

```
CSC-250-with-Cpp/
├── P1 - Snowball Team Score Checker/       # Binary search, sorting, file I/O
├── P2 - Schedule Program.../                # 2D arrays, enrollment tracking
├── P3 - Updating Program 1.../              # Feature enhancement, code evolution
├── P4 - Print Date Words from Date/         # String manipulation (C++ & C-style)
├── P5 - Structures Shirt Sales/             # Structures, enums, inventory
├── P6 - Feed Inventory App/                 # Binary file I/O, data persistence
├── P7 - Scooter/                           # OOP, classes, encapsulation
├── P8 - IntList Linkedlist/                # Linked lists, recursion, dynamic memory
├── Practice Work/                           # Additional exercises and snippets
└── Test Project/                            # Testing and experimentation
```

For detailed architecture documentation, see [docs/ARCHITECTURE.md](./docs/ARCHITECTURE.md).

## 🚀 Quickstart

### Prerequisites

- **C++ Compiler**: g++ (MinGW-w64) or MSVC (Visual Studio)
- **IDE** (recommended): Visual Studio 2022, Visual Studio Code, or Code::Blocks
- **Operating System**: Windows (primary), Linux/macOS (with modifications)

### Build & Run

Each project can be compiled independently:

#### Using g++ (Command Line)

```bash
# Navigate to a project directory
cd "P1 - Snowball Team Score Checker"

# Compile
g++ -o snowball snowball_JCA.cpp

# Run
./snowball
```

#### Using Visual Studio

1. Open the `.sln` file in the project directory (where available)
2. Build the solution (Ctrl+Shift+B)
3. Run (F5 or Ctrl+F5)

#### Using VS Code

1. Open the project folder in VS Code
2. Use the pre-configured build task (Ctrl+Shift+B)
3. Run in integrated terminal

### Example: Running the Snowball Program

```bash
cd "P1 - Snowball Team Score Checker"
g++ -o snowball snowball_JCA.cpp
./snowball
```

**Expected Output:**
```
Welcome to the Snowball Fight Team Score Checker!
[Menu displays]
Enter team ID: 182
Team 182: 37 hits, 12 times hit
Congratulations! Your team did well!
```

## 📚 Project Descriptions

### P1 - Snowball Team Score Checker
**Concepts**: Binary search, parallel arrays, sorting, file I/O

Reads team data from a file, sorts parallel arrays, and uses binary search to find and display team statistics. Demonstrates fundamental algorithm implementation.

- **File**: `snowball_JCA.cpp`
- **Input**: `snowball.txt` (team ID, hits, times hit)
- **Key Features**: Binary search algorithm, selection sort, parallel array handling

### P2 - Schedule Program for Winter at the State Park
**Concepts**: 2D arrays, table operations, user interaction

Manages enrollment for winter activities using a 2D array. Tracks participation across multiple days and activities with row/column totals.

- **File**: `winter_jca.cpp`
- **Key Features**: 2D array manipulation, table display, aggregate calculations

### P3 - Updating Program 1 to Include Another Code and Feature
**Concepts**: Code refactoring, feature addition, iterative development

Enhanced version of P1 with additional features demonstrating code evolution and maintenance.

- **File**: `snowFight2_JCA.cpp`
- **Key Features**: Extended functionality, improved user interface

### P4 - Print Date Words from Date
**Concepts**: String manipulation, C-style strings vs C++ strings

Converts numeric dates to word format using both C-style and C++ string approaches.

- **Files**: Separate implementations for C++ strings and C-style strings
- **Key Features**: String parsing, formatting, dual implementation approaches

### P5 - Structures Shirt Sales
**Concepts**: Structures, enumerated types, file I/O, arrays of structures

T-shirt sales system using structures to manage inventory, prices, and orders. Includes checkout with tax calculation.

- **File**: `shirts_jca.cpp`
- **Input**: `shirts.txt` (prices and descriptions)
- **Key Features**: Struct arrays, enums for sizes (S, M, L, XL, XXL), order management

### P6 - Feed Inventory App
**Concepts**: Binary file I/O, data persistence, inventory management

Manages feed store inventory with binary file operations for data persistence.

- **File**: `feed_store_jca.cpp`
- **Data File**: `feed.dat` (binary format)
- **Key Features**: Binary file handling, CRUD operations, persistent storage

### P7 - Scooter
**Concepts**: Object-oriented programming, classes, encapsulation

Complete OOP implementation with a Scooter class including constructors, accessors, mutators, and behavior methods.

- **Files**: `Scooter.h`, `Scooter.cpp`, `V1 Program 7.cpp`
- **Key Features**: Class design, encapsulation, constructor overloading, member functions

### P8 - IntList Linkedlist
**Concepts**: Linked lists, dynamic memory, recursion, copy constructor

Custom integer linked list implementation with insertion, deletion, traversal, and recursive counting.

- **Files**: `IntList.h`, `IntList.cpp`, `integers.cpp`
- **Key Features**: 
  - Node-based structure
  - Dynamic memory management
  - Recursive node counting
  - Copy constructor
  - Destructor for proper cleanup

## 🛠️ Development

For complete development setup, build instructions, and project structure details, see [docs/DEVELOPMENT.md](./docs/DEVELOPMENT.md).

### Quick Development Setup

1. Clone the repository
   ```bash
   git clone https://github.com/jakujobi/CSC-250-with-Cpp.git
   cd CSC-250-with-Cpp
   ```

2. Choose a project and navigate to its directory
   ```bash
   cd "P7 - Scooter/Program 7 - Scooter Objects"
   ```

3. Compile and run
   ```bash
   g++ -o scooter Scooter.cpp "V1 Program 7.cpp"
   ./scooter
   ```

## 🧪 Testing

Most projects include test data files and can be manually tested:

- **P1**: Uses `snowball.txt` for team data
- **P5**: Uses `shirts.txt` for inventory
- **P6**: Uses `feed.dat` for binary data

To test a project:
1. Ensure the data file is in the correct location
2. Compile and run the program
3. Follow the on-screen prompts
4. Verify output matches expected results

## 📖 Configuration

Most programs read configuration from data files:

| Project | Config File | Format | Purpose |
|---------|------------|--------|---------|
| P1 | snowball.txt | Text | Team ID, hits, times hit |
| P2 | None | N/A | Uses 2D array in memory |
| P5 | shirts.txt | Text | Price and shirt descriptions |
| P6 | feed.dat | Binary | Inventory data |

No environment variables are required.

## 💼 What This Project Demonstrates

This portfolio showcases practical software engineering skills valuable in professional development:

### Algorithm Implementation
- **Binary search algorithm** - O(log n) search complexity ([P1/snowball_JCA.cpp](./P1%20-%20Snowball%20Team%20Score%20Checker/snowball_JCA.cpp))
- **Sorting algorithms** - Parallel array sorting ([P1](./P1%20-%20Snowball%20Team%20Score%20Checker))

### Data Structures
- **Linked list implementation** - Custom IntList class with dynamic memory ([P8/IntList.h](./P8%20-%20IntList%20Linkedlist/IntList%20JCA/IntList.h))
- **Array-based structures** - Multi-dimensional arrays, parallel arrays ([P2](./P2%20-%20Schedule%20Program%20for%20Winter%20at%20the%20State%20Park))

### Object-Oriented Design
- **Class design** - Encapsulation, constructors, accessors/mutators ([P7/Scooter.h](./P7%20-%20Scooter/Program%207%20-%20Scooter%20Objects/Scooter.h))
- **Resource management** - Destructors, copy constructors ([P8/IntList.cpp](./P8%20-%20IntList%20Linkedlist/IntList%20JCA/IntList.cpp))

### File I/O & Data Persistence
- **Text file processing** - Reading, parsing, writing ([P1](./P1%20-%20Snowball%20Team%20Score%20Checker), [P5](./P5%20-%20Structures%20Shirt%20Sales))
- **Binary file operations** - Structured data persistence ([P6](./P6%20-%20Feed%20Inventory%20App))

### Software Engineering Practices
- **Modular programming** - Function decomposition across all projects
- **Code documentation** - Comprehensive inline comments and design docs
- **Iterative development** - Version control evident in P1 versions ([P1/Version 1.0](./P1%20-%20Snowball%20Team%20Score%20Checker/Version%201.0), [P1/Version 2.0](./P1%20-%20Snowball%20Team%20Score%20Checker/Version%202.0))

## 📁 Project Status

**Status**: Academic portfolio - Complete

This repository represents completed coursework from CSC 250 (Spring 2023). Projects are kept for portfolio and reference purposes.

### Completed Features
- ✅ All 8 major programming assignments
- ✅ Design documentation for each project
- ✅ Multiple implementation versions showing iteration
- ✅ Practice exercises and code snippets

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

**Note**: This is academic coursework. While the code is open source, please follow your institution's academic integrity policies if using this as a reference.

## 👤 Author

**John Akujobi (JCA)**
- Course: CSC 250, Spring 2023
- Institution: South Dakota State University

## 🙏 Acknowledgments

- **Prof. Paula Kurtenbach** - Course instructor, project requirements, and guidance
- **South Dakota State University** - Computer Science Department
- Course materials and project specifications from CSC 250

---

*This portfolio demonstrates practical C++ programming skills including data structures, algorithms, OOP, and file I/O - all essential for software engineering roles.*
