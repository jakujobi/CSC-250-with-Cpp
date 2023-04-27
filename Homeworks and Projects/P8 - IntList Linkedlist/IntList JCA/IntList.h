//IntList.h header file
#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

class IntList {
public:
    // Default constructor
    IntList() : head(nullptr) {}

    // Copy constructor
    IntList(const IntList& other);

    // Destructor
    ~IntList();

    // Public member functions
    void appendNode(int value);
    void insertNode(int value);
    void deleteNode(int value);
    void displayList() const;
    int countNodes() const;

private:
    // Node structure
    struct ListNode {
        int value;
        ListNode* next;
        ListNode(int value, ListNode* next = nullptr) : value(value), next(next) {}
    };

    ListNode* head;

    // Private recursive function to count nodes
    int countNodes(ListNode* node) const;
};

#endif // INTLIST_H