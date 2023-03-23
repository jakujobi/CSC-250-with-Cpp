/*
Shirt Sales Program
Allows the user to order a shirt from a SDSU T-shirt vendor.
Stores the vendor's menu in a structure and displays it in a table format.
Lets the user to choose between ordering, checking out or exiting.

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
const float TAX_RATE = 0.065; //tax rate at 6.5%

//the enumerated type for the shirt size
enum ShirtSize { S, M, L, XL, XXL };

const string SIZE_NAMES[] = { "Small - S", "Medium - M", "Large - L", "Extra Large - XL", "Extra Extra Large - XXL" };

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

void readShirtFIle();   //Read the file and set the values of the shirt structure
void Line(int num);     //Print a line of dashes
void printShirt();      //Print the menu in a table format
void printCart();       //Print the cart in a table format
int getMenuChoice();    //Get the user's menu choice
int getShirtSize();    //Get the user's shirt size choice
int getShirtQuantity(); //Get the user's shirt quantity choice
void orderShirt(int ID); //Order a shirt
float calcTotal();      //Calculate the total cost of the order
void checkOut();        //Check out the cart and print the bill





//Main Function
//!_________________________________________________________________________________________________________________________________________
int main (){
    int UID; // To hold the user's shirt ID
    int UserSize; // To hold the user's size
    int UserQuantity; // To hold the user's quantity
    int menuChoice; // To hold the user's menu choice

    readShirtFIle();    // Read the shirts from the file

    do{
        printCart(); // Print the cart

        menuChoice = getMenuChoice();   // Get the user's menu choice

        if (menuChoice > 0 && menuChoice < 6){
            UID = menuChoice - 1; // Get the shirt ID from the menu choice
            orderShirt(UID);
        }

        if (menuChoice == 6){   // Option to check out and reset the cart
            checkOut();
        }

        else if (menuChoice == 7){  // Exit the program
            exit(0);
        }

        if (menuChoice < 1 || menuChoice > 7){
            cout << "Invalid choice. Please enter number from 1 to 7" << endl;
        }

    } while (menuChoice != 7); // End of the do-while loop

    return 0;
}


//!_________________________________________________________________________________________________________________________________________
//Functions to read the file and set the values of the shirt structure
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

        sdsuShirts[i].id = i;    // Set the id of the shirt

        // Set the quantity of the shirt to 0
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                sdsuShirts[i].quantity[j] = 0;
            }
        }
    }

    // Close the file
    shirtFile.close();
}



// Prints a line of dashes
void Line(int num) {
    for (int i = 0; i < num; i++) {
        cout << "-";
    }
    cout << endl;
}


//function to print shirt
void printShirt() {

    for (int i = 0; i < NUM_SHIRTS; i++) {
        int qty = 0;

        cout << setw(3) << " | "
            << setw(2) << sdsuShirts[i].id + 1              << setw(3) << " | "
            << setw(30) << left << sdsuShirts[i].name       << setw(3) << " | "
            << setw(6) << sdsuShirts[i].cost                << setw(3) << " | ";

        
        for (int j = 0; j < 5; j++) {
                qty +=  sdsuShirts[i].quantity[j] ;
        }

        cout << setw(4) << qty                          << setw(3) << " | "
            << setw(8) << sdsuShirts[i].cost * qty      << setw(4) << " || " ;

        for (int j = 0; j < 5; j++) {
        cout << setw(4) << sdsuShirts[i].quantity[j] ;
        }


        cout << setw(4) << " || " << endl;
    }

}



// Function to print the cart
void printCart()
{
    Line(100); // Print a line of dashes

    // for (int i = 0; i < 50; i++) {  // Print spaces for the cart title
    //     cout << " ";
    // }

    cout << "  YOUR CART - " << endl;
    Line(100);
    
    cout << setw(3) << " | "
        << setw(2) << "ID"                      << setw(3) << " | "
        << setw(30) << left << "PRODUCT NAME"   << setw(3) << " | "
        << setw(6) << "COST"                    << setw(3) << " | "
        << setw(4) << "QTY"                     << setw(3) << " | "
        << setw(8) << "TOTAL"                   << setw(4) << " || "
        << setw(20)<< "DETAILS"                 << setw(4) << " || "
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

    float total = calcTotal();
    cout << setw(3) << " | "
        << "TOTAL COST: $ " << setw(8) << total << setw(4) << " || " << endl;

    Line(100); //Print a line to separate the shirts from the footer
    
}


// This function prints a menu and returns the user's choice
int getMenuChoice()
{
    int choice;

    do {
        cout << "\nMAIN MENU" << endl;

        for (int i = 0; i < NUM_SHIRTS; i++)
        {
            cout << sdsuShirts[i].id + 1 << "." << sdsuShirts[i].name << endl;
        }

        cout << "6. CHECKOUT" << endl;
        cout << "7. EXIT" << endl;
        cout << "\nEnter your choice -->:";
        cin >> choice;
        cin.clear();

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter number from 1 to 7" << endl;
        }
    } while (choice < 1 || choice > 7);
    cin.ignore(); // ignore the newline character
    return choice;
}


// Get the size of the shirt
int getShirtSize(){
    int sizeChoice;
    Line(50);
    // Print the shirt sizes and get the user's choice
    do{
        cout << "\nWhich size do you want to purchase?" << endl;
        cout << "SHIRT SIZES" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ": " << SIZE_NAMES[i] << endl;
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


// Get the quantity of the shirts that the user wants to purchase
int getShirtQuantity(){
    int qtyChoice; // The quantity of shirts that the user wants to purchase
    Line(50);   // Print line
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


// Order the shirts
void orderShirt(int ID){
    
    cout << "You have chosen" << sdsuShirts[ID].name << endl;   // Print the name of the shirt (For testing)

    // Get the quantity of the shirt
    int qtyChoice = getShirtQuantity();
    cout << "You have chosen " << qtyChoice << " shirts." << endl;   // Print the quantity of the shirt (For testing)

    // Get the size of the shirt
    int sizeChoice = getShirtSize();
    cout << "You have chosen " << sizeChoice << " size." << endl;   // Print the size of the shirt (For testing)

    // Add the shirts to the cart by updating the quantity of the shirt
    sdsuShirts[ID].quantity[sizeChoice - 1] += qtyChoice;

    return;
}

// Calculates the total cost of the order
float calcTotal(){
    float subtotal = 0; // Initialize the subtotal to 0

    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            subtotal += sdsuShirts[i].quantity[j] * sdsuShirts[i].cost;
        }
    }

    float tax = subtotal * TAX_RATE;    // 0.065 is the tax

    float total = subtotal + tax;   // add the tax to the subtotal

    return total;
}


//Checks the user out
void checkOut(){
    float total = calcTotal();    // Calculate the total cost of the order
    cout << "Your total is: $ " << fixed << setprecision(2) << total << endl;
    cout << "You have checked out.\nHave an awesome day!!" << endl;

    // Reset the cart
    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sdsuShirts[i].quantity[j] = 0;
        }
    }
}