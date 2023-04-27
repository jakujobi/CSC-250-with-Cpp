//main program
#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
    IntList myList;

    // Append nodes
    myList.appendNode(3);
    myList.appendNode(6);
    myList.appendNode(9);
    myList.displayList();

    // Insert nodes
    myList.insertNode(1);
    myList.insertNode(4);
    myList.insertNode(11);
    myList.displayList();

    // Delete nodes
    myList.deleteNode(1);
    myList.deleteNode(6);
    myList.deleteNode(11);
    myList.displayList();

    // Test copy constructor
    IntList copiedList(myList);
    copiedList.appendNode(12);
    myList.displayList();
    copiedList.displayList();

    // Count nodes
    cout << "Number of nodes in the list: " << myList.countNodes() << endl;

    return 0;
}