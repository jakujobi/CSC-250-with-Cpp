//IntList.cpp
#include "IntList.h"
using namespace std;

IntList::IntList(const IntList& other) {
    head = nullptr;
    ListNode* current = other.head;
    while (current) {
        appendNode(current->value);
        current = current->next;
    }
}

IntList::~IntList() {
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

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

void IntList::displayList() const {
    int nodeNumber = 1;
    ListNode* current = head;
    while (current) {
        cout << "Node " << nodeNumber << ": " << current->value << endl;
        current = current->next;
        nodeNumber++;
    }
}

int IntList::countNodes() const {
    return countNodes(head);
}

int IntList::countNodes(ListNode* node) const {
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->next);
}