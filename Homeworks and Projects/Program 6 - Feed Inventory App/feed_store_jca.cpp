/* Feed Inventory SOftware (FISO)
FISO helps users to keep track of their inventory.
-  adding items to the inventory
-  editing items
-  printing items
-  purchasing items
-  calculating the total value of items on hand

John Akujobi
CSC 250 - Program 6 - Feed Inventory App
03/28/2023 - Started (mostly empty code, but did design)
03/30/2023 - Updated
03/31/2023 - Completed

*/

//Bugs
/*
Bug 1: searchItem function not working
    Solution:
    - combined the searchItem function with the purchaseItem function
    - found out that i did not need the searchItem function
    - fixed the bug
Bug 2: purchaseItem function not working
    - It worked well before i combined it with the searchItem function
    Solution:
    - asked my instance of claude+ AI to find errors in my code
    - found out that it was with this line of code
        - file.seekp(static_cast<int>(file.tellg()) - static_cast<int>(sizeof(Item)), ios::beg);
        It is very difficult to remember and understand
        The syntax is super complex so, i have copied and saved it to my 2nd-mind workspace
    - fixed the bug
Bug (Infinity) - had a whole lot of syntax errors
    Solution:
    - did a lotta rewriting
    - fixed the bug...i mean bugs
*/

//Learnings
/*
    - used the file.fail instead of !file.is_open() to check if the file is open
    - tried out recursion by calling functions again
    - learn how to use animations in the loadingAnimation function
    - got a better hold of enumerated types, at least for this purpose
    - used "\a" for beeps in the loadingAnimation function

    Added more features
    - added a resetInventory function
    - added a eraseInventory function
    - added a searchItem function...ahhhh, not needed 
    - added the loadingAnimation function
        and tweaked it to make it not do the same everytime

    Tried checking if there were ways of making cooler ui in terminal with c++
    wellll...It was way more complex than i had expected
    - it needed importing a whole library
    - i am still learning and have a very long way to go to get there
    - so, i shelfed the idea for later
    Future John, you gotta learn it, coz it looks cool...like really cool
*/

//Struggles
/*
 - having problem with long complex syntax!!!!
    especially with things like:
    file.seekp(static_cast<int>(file.tellg()) - static_cast<int>(sizeof(Item)), ios::beg);
    file.write(reinterpret_cast<char*>(&item), sizeof(Item));
*/


//Libraries
#include <iostream> // cout, cin, endl
#include <string>   // string class
#include <iomanip>  // setw, setfill
#include <fstream>  // ifstream, ofstream, fstream
#include <cstring>  // strcpy
#include <thread>   // this_thread::sleep_for in the loadingAnimation function
#include <chrono>   // chrono::steady_clock

using namespace std;

const int MAX_CHAR = 30;    // Maximum length of an item name

// Enum for the choices
enum Choice {ADD_ITEM, EDIT_ITEM, PRINT_INVENTORY, PURCHASE_ITEM, CALC_TOTAL, EXIT, RESET_INVENTORY, ERASE_INVENTORY};

struct Item {
    char item [MAX_CHAR];
    int qty;
    float price;

    void printItemName() {
        //print the item name
        for (int i = 0; i < MAX_CHAR; i++) {
            cout << item[i];
        }
    }

    void printItemQty() {
        //print the item qty
        cout << setw(5) << qty;
    }

    void printItemPrice() {
        //print the item price
        cout << setw(5) << price;
    }

    int calcCost() {
        float cost;
        cost = ((qty * 1.0) * price);
        return cost;
    }
};


//! Functions _______________________________________________________________
void Line(int num); //Prints a line of dashes
int getChoice();    //Get the user's choice and call the appropriate function
void addItem(); //Add an item to the inventory
void printInventory();  //Print the inventory
void calcTotal();   //Calculate the total value of the inventory
void purchaseItem();    //Buy an item
//void searchItem();    //Search for an item...NOT Needed
void editItem();    //Edit the item name, quantity, or price
void resetInventory();  //Resets the prices and quantities of the items
void eraseInventory();  //Erases the inventory file

void loadingAnimation(int seconds); //Prints a loading animation
//Learned about this from Stack Overflow
//and repurposed it to print smiley faces




//! Main function _________________________________________________________

int main () {
    loadingAnimation(3);
    cout << "\nHIYAA!!!\n"
    << "Welcome to the Feed Inventory SOftware!\nYou can call me FISO"
    << "I can help you track your inventory by \n" 
    << "adding new items, editing items, and buying stuff.\n"
    "Lets dive in"<< endl;
    getChoice();
    return 0;
}



//! Functions _______________________________________________________________
// Prints a line of dashes
void Line(int num) {
    for (int i = 0; i < num; i++) {
        cout << "-";
    }
    cout << endl;

    //cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
}


// Asks the user for choice and calls the appropriate function
int getChoice() {
    int choice;

    do {
        //Print the main menu
        Line(50);
        cout << "FISO's USER MENU" << endl;
        do {
            cout<< "1. Add Item\n" 
                << "2. Edit Items\n"
                << "3. Print Inventory\n"
                << "4. Purchase Item\n"
                << "5. Calculate Total\n"
                << "6. Exit\n"
                << "Reset stuff\n"
                << "   7. Reset Inventory (Prices and Quantities)\n"
                << "   8. Erase Inventory (Resets everything)\n"
                << endl;
            
            //Get the user's choice
            cout << "Enter your choice (1-8): ";
            cin >> choice;
            cin.ignore();
            cin.clear();

            //Validate the user's choice
            if (choice < 1 || choice > 8) {
                cout << "OOPS! Invalid choice. Please enter number from 1 to 5" << endl;
            }

        } while (choice < 1 || choice > 8); //repeat until the user enters a valid choice

        // Call the appropriate function based on user input
        switch (choice-1) {
            case ADD_ITEM:
                addItem();
                break;
            case EDIT_ITEM:
                editItem();
                break;
            case PRINT_INVENTORY:
                printInventory();
                break;
            case PURCHASE_ITEM:
                purchaseItem();
                break;
            case CALC_TOTAL:
                calcTotal();
                break;
            case EXIT:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            case RESET_INVENTORY:
                resetInventory();
                break;
            case ERASE_INVENTORY:
                eraseInventory();
                break;
            default:
                cout << "OOPS! Invalid choice. Please enter number from 1 to 6" << endl;
                break;
        }
    } while (choice != EXIT);

    return choice;
}

// Adds an item to the inventory
void addItem() {
    Item newItem;   //create a new item instance of Item struct

    //Print Header for function
    cout << endl;
    Line(16);
    cout << "ADD ITEM" << endl;
    //Line(16);


    cout << "\nWith " << MAX_CHAR << " maximum characters,\n"
        << "Enter the item name -->: ";
    cin.getline(newItem.item, MAX_CHAR); //get the item name from the user
    // cin.ignore();
    // cin.clear();
    cout << newItem.item << " has been added to the inventory." << endl;

    //ask the user for the item quantity
    do {
        cout << "\nEnter the quantity of bags -->: ";
        cin >> newItem.qty; //get the item quantity from the user
        cin.ignore();
        cin.clear();
        if (newItem.qty < 0) {
            cout << "OOPS! You can only enter positive numbers for the quantity." << endl;
        }
    } while (newItem.qty < 0); //repeat until the user enters a valid price
    cout << newItem.qty << " of the item has been added to the inventory." << endl;

    //ask the user for the item price
    do {
        cout << "\nEnter the price per bag of the item-->: ";
        cin >> newItem.price; //get the item price from the user
        cin.ignore();
        cin.clear();
        if (newItem.price < 0) {
            cout << "OOPS! You can only enter positive numbers for the price" << endl;
        }
    } while (newItem.price < 0); //repeat until the user enters a valid price
    cout << newItem.price << " has been set as the price of the item." << endl;

    // Open the "feed.dat" file in binary append mode
    ofstream outFile("feed.dat", ios::binary | ios::app);
    if (outFile.fail()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Write the new structure to the file
    outFile.write(reinterpret_cast<const char*>(&newItem), sizeof(newItem));
    outFile.close();

    cout << "\nItem added successfully!" << endl;

    //ask the user if they want to add another item
    //uses recursive by calling addItem() again
    cout << "\nDo you want to add another item? (y/n): ";
    char repeat;
    cin >> repeat;  //get the user input for repeat
    cin.ignore();
    cin.clear();
    if (repeat == 'y' || repeat == 'Y') {
        addItem();
    }
    else {
        cout << "Returning to the main menu..." << endl;
    }
}


// Function to print the inventory in table form
void printInventory() {

    //Print Header for function
    cout << endl;
    Line(100);
    cout << "PRINT INVENTORY" << endl;

    // Open the "feed.dat" file in binary read mode
    ifstream inFile("feed.dat", ios::binary);
    if (inFile.fail()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read all structures from the file and display in table form
    Item currentItem;   //create a new item instance of Item struct
                        //put it here so it only does so if the file is opened
    Line(MAX_CHAR + 44);    

    // Printing the table header
    cout << "|| " ;
    cout << setw(MAX_CHAR) << left << "ITEM NAME"  << " | "
        << setw(10) << left << "QTY (bags)" << " | "
        << setw(10) << left << "PRICE/Bag"      << " | "
        << setw(10) << left << "TOTAL"  << "||" 
        << endl;
    
    Line(MAX_CHAR + 44);
    float totalValue = 0;   //variable to hold the total value of the inventory

    // Printing each item from the file
    while (inFile.read(reinterpret_cast<char*>(&currentItem), sizeof(currentItem))) {
        //currentItem.printItemName();
        //currentItem.printItemQty();
        //currentItem.printItemPrice();
        //currentItem.printItemTotal();
        cout << "|| " ;
        cout << setw(MAX_CHAR) << left << currentItem.item    << " | "
            << setw(10) << left << currentItem.qty     << " | "
            << setw(10) << left << currentItem.price   << " | "
             << setw(10) << left << (currentItem.qty * currentItem.price)
            << "||" << endl;

        // Calculate the total value of the inventory
        totalValue += currentItem.qty * currentItem.price;
    }
    inFile.close();

    Line(MAX_CHAR+44);
    cout << setw(MAX_CHAR + 32)
        << right << "Total Value: "
        << setw(10) << left << totalValue << endl;
}



// // Function to search for an item by name
// void searchItem() {
//     //Not Needed
// }



// Function to purchase an item by name and quantity
void purchaseItem() {
    //Print Header for function
    cout << endl;
    Line(100);
    cout << "PURCHASE ITEM" << endl;

    // Prompt user to input the name and quantity to purchase
    char item[50];
    int purchaseQty;
    cout << "Enter the name of the item to purchase: ";
    cin.getline(item, 50);
    cout << "Enter the quantity to purchase: ";
    cin >> purchaseQty;
    cin.ignore(); // Ignore newline character

    // Open the "feed.dat" file in binary mode
    fstream file;
    file.open("feed.dat", ios::in | ios::out | ios::binary);

    // Check if the file is open
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Loop through all the structures in the file and find the item that matches the item name
    Item buyItem;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&buyItem), sizeof(buyItem))) {
        if (strcmp(buyItem.item, item) == 0) {
            found = true;
            break;
        }
    }

    // Check if the item is found in the inventory
    if (found) {
        // Calculate the total price of the purchase
        double purchasePrice = buyItem.price * purchaseQty;

        // Check if the purchase quantity is greater than the available quantity
        if (purchaseQty > buyItem.qty) {
            cout << "Purchase quantity exceeds the available quantity." << endl;
            file.close();
            return;
        }

        buyItem.qty -= purchaseQty; //update the quantity

        // Write the updated inventory back to the file
        file.seekp(static_cast<int>(file.tellg()) - static_cast<int>(sizeof(buyItem)), ios::beg);
        file.write(reinterpret_cast<char*>(&buyItem), sizeof(buyItem));

        cout << "Purchase successful." << endl;
        cout << "Total price: $" << purchasePrice << endl;
    }
    else {
        cout << "Item not found." << endl;
    }

    // Close the file
    file.close();

    //ask the user if they want to buy another item
    //uses recursive by calling the function again
    cout << "\nDo you want to purchase another item? (y/n): ";
    char repeat;
    cin >> repeat;  //get the user input for repeat
    cin.ignore();
    cin.clear();
    if (repeat == 'y' || repeat == 'Y') {
        purchaseItem();
    }
    else {
        cout << "Returning to the main menu..." << endl;
    }
}



void calcTotal() {
    //Print Header for function
    cout << endl;
    Line(100);
    cout << "CALCULATE TOTAL" << endl;

    // Opening the "feed.dat" file in binary mode for reading
    ifstream inFile("feed.dat", ios::binary);
    if (inFile.fail()) {
    cerr << "Error: Unable to open file for reading" << endl;
    return;
    }

    double totalValue = 0.0;    //Initialize total value to 0.0

    // Read each structure from the file and add the value to totalValue
    Item currentItem;
    while (inFile.read(reinterpret_cast<char*>(&currentItem), sizeof(currentItem))) {
        totalValue += currentItem.qty * currentItem.price;
    }

    inFile.close();   // Close the file

    // Display the total value
    cout << "Total value of items on hand: $" << fixed << setprecision(2) << totalValue << endl;
}


// Function to edit an item in the inventory
void editItem() {
    //Print Header for function
    cout << endl;
    Line(100);
    cout << "EDIT ITEM" << endl;

    // Prompt user to input the name of the item to edit
    char itemName[50];
    cout << "Enter the name of the item to edit: ";
    cin.getline(itemName, 50);
    
    // Search for the item that matches the name
    int found = 0;
    fstream file;
    file.open("feed.dat", ios::binary|ios::in|ios::out);
    if (file.fail()) {
        cout << "Error opening file.";
        return;
    }
    Item EdItem;
    while (file.read((char *)&EdItem, sizeof(EdItem))) {
        if (strcmp(EdItem.item, itemName) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Item not found." << endl;
        file.close();
        return;
    }
    
    // Prompt user to input new values for the item
    int newQuantity;
    float newPrice;
    cout << "Enter new quantity for " << EdItem.item << ": ";
    cin >> newQuantity;
    cout << "Enter new price per bag for " << EdItem.item << ": ";
    cin >> newPrice;
    cin.ignore();  // consume newline character left in buffer
    
    // Update the inventory with the new values
    EdItem.qty = newQuantity;
    EdItem.price = newPrice;
    file.seekp(-sizeof(EdItem), ios::cur);  // move back to the start of the item
    file.write((char *)&EdItem, sizeof(EdItem));  // write the updated item back to file
    file.close();
    
    cout << "Item updated successfully." << endl;

    //ask the user if they want to edit another item
    //uses recursive by calling this function again
    cout << "\nDo you want to edit another item? (y/n): ";
    char repeat;
    cin >> repeat;  //get the user input for repeat
    cin.ignore();
    cin.clear();
    if (repeat == 'y' || repeat == 'Y') {
        editItem();
    }
    else {
        cout << "Returning to the main menu..." << endl;
    }
}


// Function to reset all the prices and quantities in the inventory
void resetInventory() {
    //Print Header for function
    cout << endl;
    Line(100);
    cout << "RESET ALL PRICES IN THE INVENTORY" << endl;

    //Ask the user if they are sure they want to reset
    //If not, stop and return to main menu
    char answer; // to hold the answer
    cout << "Are you sure you want to reset all the prices and quantities in the inventory? (y/n): ";
    cin >> answer;
    cin.ignore();  // consume newline character left in buffer
    if (answer != 'y' && answer != 'Y') {
        cout << "Phew!! Reset cancelled." << endl;
        return;
    } //the function continues if the user wants to reset

    // Open the "feed.dat" file in binary mode
    fstream file("feed.dat", ios::in | ios::out | ios::binary);
    if (file.fail()) {
        cout << "OOPS! ERROR: Unable to open file!" << endl;
        return;
    }

    // Read and update the quantities and prices for each item in the file
    Item resetItem;
    while (file.read((char*)&resetItem, sizeof(resetItem))) {
        // Reset the quantity to 0 and the price to 1.00
        resetItem.qty = 0;
        resetItem.price = 1.00;
        
        // Move the file pointer back to the beginning of the inventory
        file.seekp(-sizeof(resetItem), ios::cur);
        
        // Write the updated inventory back to the file
        file.write((char*)&resetItem, sizeof(resetItem));
    }
    
    // Close the file
    file.close();
    loadingAnimation (3);   // Display loading animation
    cout << "\n Inventory reset complete!\a" << endl;
    return;
}

// Function to erase all the items in the inventory
void eraseInventory() {
    // Open the file in write mode and truncate it to zero length
    ofstream file("feed.dat", ios::trunc);
    
    if (file.fail()) {
        cout << "Failed to open file!" << endl;
        return;
    }
    
    file.close();    // close the file

    loadingAnimation (3);   // display loading animation
    cout << "Inventory has been erased.\a" << endl;
}

void loadingAnimation(int seconds) {
    string dots;    //to store the printed stuff
    cout << "Loading...";

    //picking the animation randomly
    int choose = rand() % 5;
    switch (choose) {
        case 1:
            dots = "BEEP! ";
            break;
        case 2:
            dots = ";) ";
            break;
        case 3:
            dots = "(U 'w' U) ";
            break;
        case 4:
            dots = "BOOP! ";
            break;
        default:
            cout << "whe";
            dots = "eee";
            break;
    }

    //cout << "Loading ";
    //to make the loading animation
    for (int i = 0; i < seconds; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << dots << flush << "\a";
    }
    cout << endl;
}