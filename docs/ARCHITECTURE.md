# Architecture Overview

This document provides a detailed overview of the repository structure, project organization, and technical architecture of the CSC 250 C++ portfolio.

## Repository Structure

```
CSC-250-with-Cpp/
│
├── P1 - Snowball Team Score Checker/
│   ├── Version 1.0/                    # Initial implementation
│   ├── Version 2.0/                    # Improved version
│   ├── Requirements & Program Design/  # Design documents
│   ├── snowball_JCA.cpp               # Main source file
│   ├── snowball.txt                   # Test data
│   └── snowball_JCA.exe              # Compiled executable
│
├── P2 - Schedule Program for Winter at the State Park/
│   ├── Version 1.0/
│   ├── Requiremnts & Design/
│   ├── winter_jca.cpp                 # Main source file
│   └── winter_jca.exe
│
├── P3 - Updating Program 1 to include anotehr code and feature/
│   ├── Kajay's program/
│   ├── Requirements & Design/
│   ├── snowFight2_JCA.cpp            # Enhanced P1
│   └── snowball_2.txt
│
├── P4 - Print Date Words from Date/
│   ├── C++ Strings/                   # C++ string implementation
│   └── C-style Strings/              # C-style implementation
│
├── P5 - Structures Shirt Sales/
│   ├── Version 1.0/
│   ├── Requiremnet & Design/
│   ├── shirts_jca.cpp
│   └── shirts.txt
│
├── P6 - Feed Inventory App/
│   ├── Version 1/
│   ├── Requirements & Design/
│   ├── feed_store_jca.cpp
│   └── feed.dat
│
├── P7 - Scooter/
│   ├── Program 7 - Scooter Objects/
│   │   ├── Scooter.h                 # Class definition
│   │   ├── Scooter.cpp              # Class implementation
│   │   └── V1 Program 7.cpp         # Main driver
│   ├── Program 7 - Scooter CodeBlock/
│   └── Design documents
│
├── P8 - IntList Linkedlist/
│   ├── IntList JCA/
│   │   ├── IntList.h                 # Class definition
│   │   ├── IntList.cpp              # Implementation
│   │   └── integers.cpp             # Main driver
│   └── Design documents
│
├── Practice Work/                     # Additional exercises
│   ├── Rectangle that calculates.../
│   ├── Strings practice/
│   ├── Program Practice First week/
│   ├── Short program snippets/
│   └── Working with 2D arrays/
│
├── Test Project/                      # Testing environment
├── .github/workflows/                 # GitHub Actions
├── .vscode/                          # VS Code configuration
└── .vs/                              # Visual Studio files
```

## Project Categories

### 1. Algorithm & Search Projects

#### P1 - Snowball Team Score Checker
**Architectural Pattern**: Procedural with modular functions

**Core Components**:
- **Data Layer**: File reading (`snowball.txt`)
- **Processing Layer**: Sorting and searching algorithms
- **Presentation Layer**: User interaction and results display

**Data Flow**:
```mermaid
graph LR
    A[snowball.txt] --> B[Read File]
    B --> C[Parallel Arrays]
    C --> D[Sort Arrays]
    D --> E[Binary Search]
    E --> F[Display Results]
    F --> G[User Input Loop]
    G --> E
```

**Key Algorithms**:
- Binary search (O(log n))
- Selection sort with parallel arrays (O(n²))

#### P3 - Enhanced Snowball Program
Extension of P1 with additional features and improved user interface.

### 2. Data Structure Projects

#### P2 - Schedule Program
**Architectural Pattern**: 2D array-based data management

**Data Structure**:
```
enrollment[days][activities]
where:
  days = 5 rows (Saturdays)
  activities = 4 columns (skiing, curling, ice skating, sledding)
```

**Operations**:
- Enroll participant: `enrollment[day][activity]++`
- Calculate row totals: Sum across activities per day
- Calculate column totals: Sum across days per activity
- Overall total: Sum of all elements

#### P8 - IntList Linked List
**Architectural Pattern**: Object-oriented data structure

**Class Design**:
```cpp
class IntList {
private:
    struct ListNode {
        int value;
        ListNode* next;
    };
    ListNode* head;
    
public:
    // Constructors & Destructor
    IntList();
    IntList(const IntList& other);
    ~IntList();
    
    // Operations
    void appendNode(int value);
    void insertNode(int value);
    void deleteNode(int value);
    void displayList() const;
    int countNodes() const;
};
```

**Memory Management**:
- Dynamic allocation via `new`
- Proper cleanup via destructor
- Deep copy via copy constructor

### 3. Object-Oriented Projects

#### P7 - Scooter
**Architectural Pattern**: Class-based encapsulation

**Class Structure**:
```
Scooter
├── Private Members
│   ├── type: string
│   ├── max_speed: float
│   └── current_speed: float
│
├── Constructors
│   ├── Default constructor
│   └── Parameterized constructor
│
├── Accessors (Getters)
│   ├── getType()
│   ├── getMaxSpeed()
│   └── getCurrentSpeed()
│
└── Mutators (Setters)
    ├── setType()
    ├── setMaxSpeed()
    ├── setCurrentSpeed()
    ├── speedUp()
    ├── slowDown()
    ├── displaySpeed()
    └── hardStop()
```

**Design Principles**:
- Encapsulation: Private data, public interface
- Constructor overloading
- Separation of interface (.h) and implementation (.cpp)

### 4. File I/O Projects

#### P5 - Structures Shirt Sales
**Data Model**:
```cpp
enum Size { S, M, L, XL, XXL };

struct ShirtItem {
    string name;
    double cost;
    int qty[5];  // One for each size
};
```

**File Format** (`shirts.txt`):
```
29.50 Go Jacks! Long Sleeve
35.99 Tangled SD Button Down
...
```

**Processing Flow**:
1. Read file → populate struct array
2. Initialize quantities to 0
3. User interaction loop
4. Display menu with quantities
5. Process orders
6. Calculate totals with tax

#### P6 - Feed Inventory App
**File Type**: Binary (`.dat`)

**Features**:
- Binary file read/write
- Persistent data storage
- CRUD operations on inventory

### 5. String Processing Projects

#### P4 - Print Date Words from Date
**Dual Implementation Approach**:

1. **C++ Strings**: Uses `std::string` and string class methods
2. **C-style Strings**: Uses character arrays and `<cstring>` functions

**Transformation Example**:
```
Input:  12/25/2023
Output: December 25th, 2023
```

## Common Design Patterns

### Modular Function Design
All projects follow a modular approach with separated concerns:

```cpp
// Typical structure
int main() {
    // 1. Initialization
    initializeData();
    
    // 2. Main processing loop
    while (!userWantsToQuit) {
        displayMenu();
        int choice = getUserChoice();
        processChoice(choice);
    }
    
    // 3. Cleanup
    cleanup();
    return 0;
}
```

### Menu-Driven Interaction
Most programs use a consistent menu pattern:
1. Display options
2. Get user input
3. Validate input
4. Execute corresponding function
5. Display results
6. Loop back to menu

### Error Handling
Common error handling approaches:
- File validation before operations
- Input validation with re-prompts
- Bounds checking for arrays
- Null pointer checks for linked lists

## Data Flow Patterns

### File → Process → Display
```
[Data File] → [Read Function] → [Data Structure] → [Process Function] → [Display Function]
```

### User Input → Validate → Process
```
[User Input] → [Validation Function] → [Processing] → [Results] → [Display]
```

## Build Configuration

### Visual Studio Projects
Projects P7 and P8 include `.sln` (solution) files for Visual Studio.

**Build Process**:
1. Open `.sln` file
2. Visual Studio loads project configuration
3. Build → Compile → Link → Execute

### VS Code Configuration
`.vscode/tasks.json` provides build configuration:
- Compiler: `g++.exe` (MinGW-w64)
- Flags: `-fdiagnostics-color=always -g`
- Output: `.exe` in project directory

### Command Line Build
```bash
g++ [flags] source.cpp -o executable
```

## Version Evolution

Several projects show iterative development:

**P1 Versions**:
- Version 1.0: Initial implementation
- Version 2.0: Improvements and refinements
- Final: `snowball_JCA.cpp`

This demonstrates:
- Code evolution and refactoring
- Incremental feature addition
- Bug fixes and improvements

## Documentation Standards

Each project includes:
1. **Source Code Comments**:
   - Program header with description, author, date, class
   - Requirements from instructor
   - Function descriptions
   - Algorithm explanations
   - Bug tracking comments

2. **Design Documents** (`.docx`):
   - Program requirements
   - Flowcharts
   - Design decisions
   - Test cases

3. **Diagrams** (`.drawio`, `.png`):
   - Structure charts
   - Class diagrams
   - Function relationships

## Technical Stack

**Language**: C++
- Standard: C++11/14 (based on compiler settings)
- Style: Mix of procedural and object-oriented

**Compilers**:
- GCC (g++) via MinGW-w64
- MSVC (Visual Studio)

**IDEs**:
- Visual Studio 2022
- Visual Studio Code
- Code::Blocks (for some projects)

**Tools**:
- Git for version control
- diagrams.net (draw.io) for diagrams

## Scalability Considerations

### Current Limitations
- Fixed-size arrays in some projects (e.g., 50 teams in P1)
- No database integration
- Local file storage only
- Single-user applications

### Potential Improvements
- Use `std::vector` for dynamic sizing
- Implement proper error logging
- Add unit testing framework
- Use modern C++ features (C++17/20)
- Add configuration files for settings

## Security Considerations

**Current State**:
- Basic input validation
- No authentication required
- Local file access only
- No network operations

**Good Practices Used**:
- Memory cleanup (destructors)
- Bounds checking in some areas
- Input validation for menu choices

**Areas for Improvement**:
- More robust input validation
- Buffer overflow protection
- Exception handling

## Future Architectural Improvements

1. **Modern C++ Features**:
   - Smart pointers (`unique_ptr`, `shared_ptr`)
   - Range-based for loops
   - Lambda expressions

2. **Design Patterns**:
   - Factory pattern for object creation
   - Strategy pattern for algorithms
   - Observer pattern for UI updates

3. **Testing**:
   - Unit test framework (Google Test)
   - Integration tests
   - Automated testing in CI/CD

4. **Code Organization**:
   - Namespace usage
   - Header guards replaced with `#pragma once`
   - CMake for cross-platform builds

---

This architecture supports learning progression from procedural to object-oriented programming, demonstrating fundamental computer science concepts in practical applications.
