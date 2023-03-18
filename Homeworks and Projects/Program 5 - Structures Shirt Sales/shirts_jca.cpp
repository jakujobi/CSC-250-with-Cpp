/*
Shirt Sales Program
John Akujobi
CSC 250
03/17/2023
*/

/* Description of program:
## **Shirt Sales Program**

The Shirt Sales program allows the user to order a shirt from a SDSU T-shirt vendor. The program stores the vendor's menu in a structure and displays it in a table format. The program allows the user to choose between ordering, checking out or exiting.

### **Program Features**

- Store vendor's menu in a structure that includes name, cost, and quantity for each size.
    
    
    | Field Name | Description |
    | --- | --- |
    | name | string |
    | cost | float/double |
    | qty | 5 element int array with qty for each size |
- Use an enumerated type for the size that contains the following enumerators: S, M, L, XL, XXL.
- Create an array of 5 structures and initialize the cost and name fields with the data from the shirts.txt file.

```
29.50 Go Jacks! Long Sleeve
35.99 Tangled SD Button Down
19.50 Engineer Jack T-shirt
44.50 Jacks Rain Jacket
31.99 Go Jacks! Fleece
```

- Set the qty fields to 0 when you read the file.

Using a loop, do the following:

- Display the menu in a numbered table with columns for the name, cost, and quantity for each size. Include an additional column for the total (cost*qty) for each item and print the order total at the bottom of the total column.
- Allow the user to choose between ordering, checking out, or exiting.
- Use separate functions to read the file, print the menu and print the bill.
- When the user chooses to checkout, print the bill with tax. Assume the tax rate is 6.5%.
Loop back to re-display the menu with the quantities reset to 0 to take the next order.

Use separate functions to read the file, print the menu and print the bill.  Your output should be well-organized, neat, and easy to read.

### **Additional Features to Add**

- Add the ability for the user to select the shirt size and quantity they wish to order.
- Implement error checking to ensure that the user enters a valid choice.
- Add the ability for the user to view their order history and reorder previous orders.
- Implement a search function to allow the user to search for a specific item in the menu.
- Allow the user to add custom text to the shirt, such as a name or custom message.

### **Concepts to Use**

- Structured programming concepts, including structures, functions, and loops.
- Input and output operations in C.
- String classes
- Enumerated types.
- File I/O operations.
- Arithmetic operations and basic data types in C.
- Error handling and input validation.
*/



/*Notes:
- Learned how to use structures and how to use them in a program
- Learned about member functions to avoid having to pass in the structure as a parameter
- Learned coding standards related to {} and indentation
    - I can put the opening brace on the same line as the function, instead of the next line
    - Makes the overall number of lines of code smaller
    - and easier to track matching braces
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Global Constants
const int NUM_SHIRTS = 5;

enum ShirtSize { S, M, L, XL, XXL };


//Structures
struct Shirt {
    //Fields or Member Variables of the Shirt Structure
    int id;
    string productName;
    float cost;
    int quantity[5];

    int Qty = 0;
    for (int i = 0; i < NUM_SHIRTS; i++) {
        Qty += quantity[i];
    }


    //Methods or Member Functions of the Shirt Structure
    void printShirt() {
        cout << setw(4) << id              << setw(1) << "|"
            << setw(30) << productName     << setw(1) << "|"
            << setw(6) << cost             << setw(1) << "|"
            << setw(4) << Qty              << setw(1) << "|"
            << setw(8) << cost * Qty       << setw(2) << "||" ;

        for (int i = 0; i < 5; i++) {
            cout << setw(4) << quantity[i] ;
        }

        cout << setw(2) << "||" << endl;

    }

}; //End of Shirt Structure

//Functions
void readShirtFIle(Shirt shirts[]);
void printMainMenu(Shirt shirts[]);

void printBill(Shirt shirts[]);

void Line(int num);
void Line(int num) {
    for (int i = 0; i < num; i++) {
        cout << "_";
    }
    cout << endl;
}

void printCart(Shirt shirts[]);
void printCart(Shirt shirts[])
{
    Line(80);
    cout << "YOUR CART" << endl;
    Line(80);
    cout << endl;
    
    cout << setw(1) << "|"
        << setw(4) << "ID"             << setw(1) << "|"
        << setw(30) << "Product Name"   << setw(1) << "|"
        << setw(6) << "Cost"            << setw(1) << "|"
        << setw(4) << "Qty"             << setw(1) << "|"
        << setw(8) << "Total"           << setw(2) << "||"
        << setw(20)<< "Details"         << setw(2) << "||"
        << endl;

    cout << setw(1) << "|"
        << setw(4) << " "          << setw(1) << "|"
        << setw(30) << " "          << setw(1) << "|"
        << setw(6) << "  $  "       << setw(1) << "|"
        << setw(4) << " "           << setw(1) << "|"
        << setw(8) << "Cost*Qty"    << setw(2) << "||"
        << setw(20)<< "Details"     << setw(2) << "||"
        << endl;
}
