//IntList.cpp
#include "IntList.h"
using namespace std;

// Constructor
IntList::IntList(const IntList& other) {
    head = nullptr;
    ListNode* current = other.head;
    while (current) {
        appendNode(current->value);
        current = current->next;
    }
}

// Destructor
IntList::~IntList() {
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// Append a node to the end of the list
void IntList::appendNode(int value) {
    if (!head) {
        head = new ListNode(value);
    }
    else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
}

// Insert a node in the list
void IntList::insertNode(int value) {
    if (!head || head->value >= value) {
        head = new ListNode(value, head);
    }
    else {
        ListNode* current = head;
        while (current->next && current->next->value < value) {
            current = current->next;
        }
        current->next = new ListNode(value, current->next);
    }
}

// Delete a node from the list
void IntList::deleteNode(int value) {
    if (!head) return;

    if (head->value == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* current = head;
    while (current->next && current->next->value != value) {
        current = current->next;
    }

    if (current->next) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Display the list
void IntList::displayList() const {
    int nodeNumber = 1;
    ListNode* current = head;
    while (current) {
        cout << "Node " << nodeNumber << ": " << current->value << endl;
        current = current->next;
        nodeNumber++;
    }
}

// Count the number of nodes in the list
int IntList::countNodes() const {
    return countNodes(head);
}

// Count the number of nodes in the list - private function wrapper
int IntList::countNodes(ListNode* node) const {
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->next);
}