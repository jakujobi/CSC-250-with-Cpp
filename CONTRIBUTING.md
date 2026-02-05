# Contributing Guidelines

Thank you for your interest in this project! This repository is primarily an academic portfolio showcasing coursework from CSC 250 at South Dakota State University.

## Nature of This Repository

This is an **educational portfolio** containing completed coursework. As such:

- The projects represent completed assignments from Spring 2023
- The code serves as a reference and portfolio piece
- The repository is maintained primarily for demonstration purposes

## Academic Integrity Notice

**Important**: If you are a student taking a similar course:

**Please respect your institution's academic integrity policies**

- This code is provided for reference and learning purposes
- Copying code directly for your assignments is considered plagiarism
- Use this repository to:
  - ✅ Understand concepts and approaches
  - ✅ See implementation examples
  - ✅ Learn coding patterns and structure
  - ❌ NOT to submit as your own work
  - ❌ NOT to copy without understanding

## Types of Contributions Welcome

While this is academic work, contributions that enhance the educational value are welcome:

### Documentation Improvements

- Clarifying existing comments
- Adding explanatory notes
- Correcting typos or grammar
- Improving README or documentation files

### Code Quality Enhancements

- Bug fixes (if any are found)
- Code cleanup or refactoring for clarity
- Adding comments to complex sections
- Improving code formatting consistency

### Educational Additions

- Alternative implementations with explanations
- Performance comparisons
- Additional test cases
- Code analysis or complexity notes

### Not Appropriate

- ❌ Removing or altering original assignment code
- ❌ Adding features that would change the original assignment scope
- ❌ Submitting solutions to different assignments

## 🔧 How to Contribute

### Reporting Issues

If you find bugs, unclear documentation, or have suggestions:

1. **Check existing issues** first to avoid duplicates
2. **Open a new issue** with:
   - Clear, descriptive title
   - Detailed description of the issue
   - Steps to reproduce (for bugs)
   - Suggested improvement (for enhancements)

### Submitting Changes

1. **Fork the repository**

   ```bash
   # Click "Fork" button on GitHub
   ```
2. **Clone your fork**

   ```bash
   git clone https://github.com/YOUR-USERNAME/CSC-250-with-Cpp.git
   cd CSC-250-with-Cpp
   ```
3. **Create a feature branch**

   ```bash
   git checkout -b feature/your-improvement-name
   ```
4. **Make your changes**

   - Follow existing code style
   - Add comments explaining your changes
   - Test your changes
5. **Commit with clear messages**

   ```bash
   git add .
   git commit -m "Brief description of changes"
   ```
6. **Push to your fork**

   ```bash
   git push origin feature/your-improvement-name
   ```
7. **Create a Pull Request**

   - Go to the original repository
   - Click "New Pull Request"
   - Provide a clear description of your changes
   - Explain why the changes improve the project

## Code Style Guidelines

### C++ Conventions

Follow the existing style in the codebase:

```cpp
// Functions: camelCase
void calculateTotal();
int getUserInput();

// Variables: camelCase
int studentCount;
double averageScore;

// Constants: UPPER_CASE
const int MAX_STUDENTS = 100;

// Classes: PascalCase
class StudentRecord;
```

### Comment Style

```cpp
// Single-line comments for brief explanations
int count = 0;  // Initialize counter

/* Multi-line comments for complex logic
   or detailed explanations spanning
   multiple lines */
```

### File Headers

Maintain the existing header format:

```cpp
/*
Program Name - Brief Description
Author: John Akujobi (or "Modified by: Your Name")
Date: Original date (Modified: Your date if changed)
Class: CSC 250
*/
```

## Pull Request Checklist

Before submitting a PR, ensure:

- [ ] Code compiles without errors
- [ ] Code compiles without warnings (`g++ -Wall`)
- [ ] Changes are documented (comments and/or README updates)
- [ ] Commit messages are clear and descriptive
- [ ] Changes align with the educational purpose of the repository
- [ ] No original assignment solutions are removed or significantly altered
- [ ] Academic integrity is respected

## Testing Your Changes

Before submitting:

1. **Compile the affected project**

   ```bash
   cd "Project Directory"
   g++ -Wall -o program source.cpp
   ```
2. **Test basic functionality**

   - Run the program
   - Test with valid inputs
   - Test with edge cases
   - Verify expected output
3. **Check for memory issues** (if applicable to P7/P8)

   ```bash
   # Linux/macOS with valgrind
   valgrind ./program
   ```

## Communication

### Getting Help

- **GitHub Issues**: For bugs, suggestions, or questions
- **Discussions**: For general questions about the code or concepts
- **Pull Requests**: Include detailed description and context

### Response Time

As this is a portfolio project maintained by one person:

- Issues and PRs will be reviewed as time permits
- Please be patient and respectful
- Clear, well-documented contributions are prioritized

## What Makes a Good Contribution

Great contributions to this educational repository:

1. **Improve Understanding**

   - Make code more readable
   - Add helpful comments
   - Clarify complex sections
2. **Fix Issues**

   - Correct bugs
   - Fix typos or documentation errors
   - Improve error handling
3. **Enhance Quality**

   - Improve code structure
   - Add meaningful tests
   - Optimize without changing functionality
4. **Respect the Original Work**

   - Preserve the educational context
   - Maintain the original assignment structure
   - Add value without replacing content

## Learning Resources

If you're learning C++, consider these resources:

- [cplusplus.com](https://www.cplusplus.com/) - Reference and tutorials
- [LearnCpp.com](https://www.learncpp.com/) - Comprehensive C++ tutorial
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - Best practices

## License

By contributing, you agree that your contributions will be licensed under the same GNU General Public License v3.0 that covers this project.

See [LICENSE](LICENSE) file for details.

## Thank You

Thank you for considering contributing to this educational project! Your improvements help make this a better learning resource for others.

---

**Questions?** Open an issue with the `question` label.
