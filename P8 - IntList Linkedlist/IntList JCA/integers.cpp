/*
IntList Program 

Created by: John Akujobi
Class: CSC 250
Date: 4/28/2023

Description: This program creates a linked list of integers. It has the following functions:
	- appendNode: appends a node to the end of the list
	- insertNode: inserts a node in the list
	- deleteNode: deletes a node from the list
	- displayList: displays the list
	- countNodes: counts the number of nodes in the list
	- copy constructor: copies the list

*/

//main program
#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
    IntList myList; // Create an empty list

    // Append nodes
    myList.appendNode(3);
    myList.appendNode(6);
    myList.appendNode(9);
    cout << "\nList with appended nodes(3,6,9): \n";
    myList.displayList();

    // Insert nodes
    myList.insertNode(1);
    myList.insertNode(4);
    myList.insertNode(11);
    cout << "\nList with inserted nodes (1,4,11): \n";
    myList.displayList();

    // Delete nodes
    myList.deleteNode(1);
    myList.deleteNode(6);
    myList.deleteNode(11);
    cout << "\nList with deleted nodes (1,6,11): \n";
    myList.displayList();

    // Test copy constructor
    cout << "\n\nTesting Copy Constructor: \n";
    IntList copiedList(myList); // Copy the list
 
    cout << "\nOriginal list:\n";
    myList.displayList();
    cout << "There are " << myList.countNodes() << " nodes in the original list\n" << endl;

    cout << "\nCopied list:\n";
    copiedList.displayList();   
    cout << "There are " << copiedList.countNodes() << " nodes in the copied list\n" << endl;

    copiedList.appendNode(12); // Append nodes to copied list
    copiedList.appendNode(15);
    cout << "\nCopied list after appending nodes:\n";
    copiedList.displayList();
    // Count nodes
    cout << "There are " << myList.countNodes() << " nodes in the list\n" << endl;

    return 0;
}