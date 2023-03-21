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

//the number of shirts in the vendor's menu
const int NUM_SHIRTS = 5;
const int MAX_QTY = 100;

//the enumerated type for the shirt size
enum ShirtSize { S, M, L, XL, XXL };

const string SIZE_NAMES[] = { "Small", "Medium", "Large", "X-Large", "XX Large" };

//Structures
struct Shirt {
    //Fields or Member Variables of the Shirt Structure
    int id;
    string name;
    float cost;
    int quantity[5];
}; //End of Shirt Structure

//Array of structures that stores the shirts in the vendor's menu
Shirt sdsuShirts[NUM_SHIRTS];

//Functions
//!_________________________________________________________________________________________________________________________________________


//function to print shirt
void printShirt();
void printShirt() {
        int qty = 0;

    for (int i = 0; i < NUM_SHIRTS; i++) {
        cout << setw(3) << " | "
            << setw(2) << sdsuShirts[i].id                  << setw(3) << " | "
            << setw(30) << left << sdsuShirts[i].name       << setw(3) << " | "
            << setw(6) << sdsuShirts[i].cost                << setw(3) << " | ";

        for (int i = 0; i < NUM_SHIRTS; i++) {
            qty += sdsuShirts[i].quantity[i];
        }

        cout << setw(4) << qty                          << setw(3) << " | "
            << setw(8) << sdsuShirts[i].cost * qty      << setw(4) << " || " ;

        for (int i = 0; i < 5; i++) {
            cout << setw(4) << sdsuShirts[i].quantity[i] ;
        }

        cout << setw(4) << " || " << endl;
    }

}



//Functions to read the file and set the values of the shirt structure
void readShirtFIle();
void readShirtFIle() {
    // Open the file
    ifstream shirtFile("shirts.txt");

    // Check if file is open
    if (!shirtFile) {
        cout << "\nError!\nUnable to open file shirts.txt" << endl;
        exit(1);
    }

    // Read the file
    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        shirtFile >> sdsuShirts[i].cost;
        getline(shirtFile, sdsuShirts[i].name);

        // Set the id of the shirt
        sdsuShirts[i].id = i + 1;

        // Set the quantity of the shirt to 0
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                sdsuShirts[i].quantity[j] = 0;
            }
        }

        // Ignore the newline character
        //shirtFile.ignore();
        //Nah, found out that doing this removes the first character of the next line
    }

    // Close the file
    shirtFile.close();
}



// Prints a line of dashes
void Line(int num);
void Line(int num) {
    for (int i = 0; i < num; i++) {
        cout << "-";
    }
    cout << endl;
}


// Function to print the cart
void printCart();
void printCart()
{
    Line(100);
    cout << "  YOUR CART" << endl;
    Line(100);
    
    cout << setw(3) << " | "
        << setw(2) << "ID"                      << setw(3) << " | "
        << setw(30) << left << "Product Name"   << setw(3) << " | "
        << setw(6) << "Cost"                    << setw(3) << " | "
        << setw(4) << "Qty"                     << setw(3) << " | "
        << setw(8) << "Total"                   << setw(4) << " || "
        << setw(20)<< "Details"                 << setw(4) << " || "
        << endl;

    cout << setw(3) << " | "
        << setw(2) << " "               << setw(3) << " | "
        << setw(30) << left << " "      << setw(3) << " | "
        << setw(6) << "  $  "           << setw(3) << " | "
        << setw(4) << " "               << setw(3) << " | "
        << setw(8) << "Cost*Qty"        << setw(4) << " || "

        << setw(4) << "S"
        << setw(4) << "M"
        << setw(4) << "L"
        << setw(4) << "XL"
        << setw(4) << "XXL"
        << setw(4) << " || "   << endl;

    Line(100); //Print a line to separate the header from the shirts

    printShirt();

    Line(100); //Print a line to separate the shirts from the footer
}


// This function prints a menu and returns the user's choice
int getMenuChoice();
int getMenuChoice()
{
    int choice;
    cout << endl;
    cout << "MAIN MENU" << endl;
    cout << "1. Order" << endl;
    cout << "2. Checkout" << endl;
    cout << "3. Exit" << endl;
    cout << "\nEnter your choice -->:";
    cin >> choice;
    cin.clear();
    
    while (choice != '1' && choice != '2' && choice != '3'){
        cout << "Invalid choice. Please choose 1,2, or 3." << endl;
        cout << "MAIN MENU" << endl;
        cout << "1. Order" << endl;
        cout << "2. Checkout" << endl;
        cout << "3. Exit" << endl;
        cout << "\nEnter your choice -->:";
        cin >> choice;
        cin.clear();
    }
    cin.ignore(); // ignore the newline character
    return choice;
}


int getShirtChoice();
int getShirtChoice(){
    int shirtID;

    do{
        cout << "\nWhich shirt do you want to purchase?" << endl;
        cout << "SHIRTS" << endl;
        
        for (int i = 0; i < NUM_SHIRTS; i++) {
            cout << sdsuShirts[i].id << ". " << sdsuShirts[i].name << endl;
        }

        // Get the user's choice
        cout << "\nEnter your choice -->:";
        cin >> shirtID;
        cin.clear();
        cin.ignore();

        if (shirtID < 1 || shirtID > NUM_SHIRTS){
            cout << "Invalid choice.\nPlease type in a number between 1 and " << NUM_SHIRTS << endl;
        }

    } while (shirtID < 1 || shirtID > NUM_SHIRTS);

    shirtID --; // Decrement the shirtID by 1 to get the index of the shirt

    cout << "Shirt ID: " << shirtID << endl;

    return shirtID;
}


// Get the size of the shirt
int getShirtSize();
int getShirtSize(){
    int sizeChoice;

    // Print the shirt sizes and get the user's choice
    do{
        cout << "\nWhich size do you want to purchase?" << endl;
        cout << "SHIRT SIZES" << endl;
        for (int i = 0; i < 5; i++) {
            cout << SIZE_NAMES[i] << endl;
        }

        // Get the user's shirt choice
        cout << "Enter a number for the shirt size -->:";
        cin >> sizeChoice;
        cin.clear();
        cin.ignore();

        if (sizeChoice < 1 || sizeChoice > 5){
            cout << "Invalid size. Please enter 1, 2, 3, 4, or 5." << endl;
        }
    } while (sizeChoice < 1 || sizeChoice > 5);

    return sizeChoice;
}

int getShirtQuantity();
int getShirtQuantity(){
    int qtyChoice;

    // Get the quantity of the shirt
    do{
        cout << "\nHow many shirts do you want to purchase?" << endl;
        cout << "Enter a number for the quantity -->:";
        cin >> qtyChoice;
        cin.clear();
        cin.ignore();

        if (qtyChoice < 1 || qtyChoice > MAX_QTY){
            cout << "\nInvalid quantity.\nPlease enter a number between 1 and " << MAX_QTY << endl;
        }
    } while (qtyChoice < 1 || qtyChoice > MAX_QTY);

    return qtyChoice;
}




void orderShirt(int UserShirtID, int ShirtSize, int ShirtQuantity);
void orderShirt(int UserShirtID, int ShirtSize, int ShirtQuantity){
    int qtyChoice;

    //sdsuShirts[shirtID].quantity[size - 1] += qty;
}


//Main Function
//!_________________________________________________________________________________________________________________________________________
int main (){
    int UserShirtID; // To hold the user's shirt ID
    int UserSize; // To hold the user's size
    int UserQuantity; // To hold the user's quantity
    int menuChoice; // To hold the user's menu choice

    // read the shirts from the file
    readShirtFIle();

    // print the cart
    printCart();

    // Get the user's menu choice
    menuChoice = getMenuChoice();

    // Process the user's menu choice
    switch (menuChoice){
        case 1:
            UserShirtID = getShirtChoice();
            UserSize = getShirtSize();
            UserQuantity = getShirtQuantity();

            break;
        case 2:
            printBill();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please choose 1,2, or 3." << endl;
            break;
    }

    return 0;
}