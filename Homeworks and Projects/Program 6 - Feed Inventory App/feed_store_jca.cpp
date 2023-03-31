#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <thread>
#include <chrono>

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
    << "I can help you track your inventory by" 
    << "adding new items, editing items, and buying stuff."
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
        Line(16);
        cout << "FISO's USER MENU" << endl;
        do {
            cout<< "1. Add Item\n" 
                << "2. Edit Items\n"
                << "3. Print Inventory\n"
                << "4. Purchase Item\n"
                << "5. Calculate Total\n"
                << "6. Exit\n\n"
                << "Reset stuff\n"
                << "   7. Reset Inventory\n"
                << "   8. Erase Inevtory\n"
                << endl;
            cout << "Enter your choice (1-8): ";
            cin >> choice;
            cin.ignore();
            cin.clear();

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
                break;
            case RESET_INVENTORY:
                resetInventory();
                break;
            case ERASE_INVENTORY:
                cout << "Erase Inventory" << endl;
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
    if (!outFile) {
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
    cin >> repeat;
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
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read all structures from the file and display in table form
    Item currentItem;

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



// Function to search for an item by name
void searchItem() {
    //Not Needed
}



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

    // Loop through all the structures in the file and find the record that matches the item name
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

        // Update the quantity of the item in the record
        buyItem.qty -= purchaseQty;

        // Write the updated record back to the file
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
}



void calcTotal() {
    //Print Header for function
    cout << endl;
    Line(100);
    cout << "CALCULATE TOTAL" << endl;

    // Opening the "feed.dat" file in binary mode for reading
    ifstream inFile("feed.dat", ios::binary);
    if (!inFile) {
    cerr << "Error: Unable to open file for reading" << endl;
    return;
    }

    // Initialize total value to 0
    double totalValue = 0.0;

    // Read each structure from the file and add the value to totalValue
    Item currentItem;
    while (inFile.read(reinterpret_cast<char*>(&currentItem), sizeof(currentItem))) {
        totalValue += currentItem.qty * currentItem.price;
    }

    // Close the file
    inFile.close();

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
    
    // Search for the record that matches the name
    int found = 0;
    fstream file;
    file.open("feed.dat", ios::binary|ios::in|ios::out);
    if (!file) {
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
    
    // Update the record with the new values
    EdItem.qty = newQuantity;
    EdItem.price = newPrice;
    file.seekp(-sizeof(EdItem), ios::cur);  // move back to the start of the record
    file.write((char *)&EdItem, sizeof(EdItem));  // write the updated record back to file
    file.close();
    
    cout << "Item updated successfully." << endl;
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
    if (!file) {
        cout << "OOPS! ERROR: Unable to open file!" << endl;
        return;
    }

    loadingAnimation (3);

    // Read and update the quantities and prices for each record in the file
    Item resetItem;
    while (file.read((char*)&resetItem, sizeof(resetItem))) {
        // Reset the quantity to 0 and the price to 1.00
        resetItem.qty = 0;
        resetItem.price = 1.00;
        
        // Move the file pointer back to the beginning of the record
        file.seekp(-sizeof(resetItem), ios::cur);
        
        // Write the updated record back to the file
        file.write((char*)&resetItem, sizeof(resetItem));
    }
    
    // Close the file
    file.close();
    
    cout << "\n Inventory reset complete!" << endl;
    return;
}

// Function to erase all the items in the inventory
void eraseInventory() {
    // Open the file in write mode and truncate it to zero length
    ofstream file("feed.dat", ios::trunc);
    
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }
    
    file.close();
    cout << "Inventory has been erased." << endl;
}

void loadingAnimation(int seconds) {
    int choose = rand()%4;
    string dots;
    
    cout << "Loading...";
    if (choose == 1) {
        dots = "BEEP! ";
    }
    else if (choose == 2) {
        dots = ";) ";
    }
    else if (choose == 3) {
        dots = "(U 'w' U) ";
    }
    else {
        cout << "whe";
        dots = "e";
    }

    //cout << "Loading ";

    for (int i = 0; i < seconds; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << dots << flush;
    }


    cout << endl;
}