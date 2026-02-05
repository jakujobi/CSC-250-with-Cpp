# Security Policy

## Overview

This repository contains educational C++ code for academic purposes. While security is not a primary focus of these beginner-level projects, this document outlines security considerations and how to report any concerns.

## Security Context

**Type**: Academic portfolio/coursework  
**Environment**: Local execution, no network services  
**Data**: Sample text files, no sensitive information  

### Current Security Posture

These projects were designed as learning exercises and include:

✅ **What is implemented**:
- Basic input validation for menu choices
- File access validation
- Memory cleanup (destructors in OOP projects)
- No network communication (zero attack surface from network)

⚠️ **Known limitations** (acceptable for educational scope):
- Limited input sanitization
- Fixed-size buffers in some projects
- Basic error handling
- No authentication or authorization (not needed for local programs)
- No encryption (data is non-sensitive sample data)

## Security Considerations by Project

### P1-P6: File I/O Projects
**Potential Concerns**:
- File path validation is minimal
- Buffer sizes are fixed
- No validation of file content format

**Mitigation**:
- Programs only read from specified local files
- No user-controlled file paths
- No network access

### P7-P8: Object-Oriented Projects
**Potential Concerns**:
- Dynamic memory allocation without smart pointers
- Manual memory management

**Mitigation**:
- Destructors properly implemented
- Copy constructors handle deep copies
- Tested for basic memory leaks

## Not Security Issues

The following are **not** considered security vulnerabilities in this educational context:

- Use of `using namespace std` (style choice, not a security issue)
- Fixed-size arrays (design choice for learning)
- Lack of exception handling (not covered in CSC 250 scope)
- Simple error messages (educational code)
- Use of C-style strings in P4 (educational comparison)

## Reporting a Security Concern

### For Actual Vulnerabilities

If you discover a genuine security issue that could affect users who compile and run this code:

1. **Do NOT** open a public issue
2. **Send a private report** via:
   - GitHub Security Advisories (preferred)
   - Or email: [Create an issue requesting contact information]

### For Educational Improvements

If you have suggestions for improving security practices as learning examples:

1. Open a regular GitHub issue
2. Tag it with `enhancement` and `security`
3. Explain the educational value of the improvement

## Security Best Practices (For Learning)

If you're a student learning from this code, consider these improvements for your own projects:

### Input Validation
```cpp
// Basic validation (current approach)
if (choice < 1 || choice > 3) {
    cout << "Invalid choice" << endl;
}

// Enhanced validation (recommended)
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input type" << endl;
}
```

### Buffer Safety
```cpp
// Fixed-size array (current approach in some projects)
char buffer[100];

// Modern C++ (recommended for new projects)
string buffer;  // Dynamically sized, safer
vector<int> data;  // Dynamically sized array
```

### Memory Management
```cpp
// Manual management (current approach in P8)
~IntList() {
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// Modern C++ (recommended for new projects)
unique_ptr<ListNode> head;  // Automatic cleanup
```

### File Access
```cpp
// Basic approach (current)
ifstream file("data.txt");

// Enhanced approach (recommended)
ifstream file("data.txt");
if (!file.is_open()) {
    cerr << "Error: Cannot open file" << endl;
    return 1;
}
```

## Secure Coding Resources

For students wanting to learn more about secure C++ programming:

- [CERT C++ Coding Standard](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [OWASP C++ Security](https://owasp.org/www-community/vulnerabilities/)

## Educational Security Checklist

When writing your own C++ programs, consider:

- [ ] Validate all user input
- [ ] Check file operations for success
- [ ] Use `std::string` instead of C-style strings when possible
- [ ] Avoid fixed-size buffers for user input
- [ ] Handle errors gracefully
- [ ] Free all dynamically allocated memory
- [ ] Use smart pointers (C++11+) for automatic memory management
- [ ] Check array bounds before access
- [ ] Avoid buffer overflows in string operations
- [ ] Clear sensitive data from memory when done

## Scope

This security policy applies to:
- All C++ source code in this repository
- Build configurations and scripts
- Documentation

This security policy does NOT apply to:
- Third-party tools (compilers, IDEs)
- Operating system security
- Network security (no network code exists)

## Updates

This security policy may be updated as:
- New security considerations are identified
- The codebase evolves
- Security best practices change

Last updated: February 5, 2026

## Disclaimer

This is educational code. It is provided "as is" without warranty of any kind. Users should:
- Review and understand code before running
- Use appropriate security practices in production code
- Not use this code in security-critical applications without thorough review and hardening

---

*This security policy is adapted for an academic portfolio. The code prioritizes learning over production-grade security.*
