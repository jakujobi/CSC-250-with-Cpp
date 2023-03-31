#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_CHAR = 30;    // Maximum length of an item name

// Enum for the choices
enum Choice {ADD_ITEM, PRINT_INVENTORY, PURCHASE_ITEM, CALC_TOTAL, EXIT};

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
void Line(int num);
int getChoice();
void addItem();
void printInventory();
void calcTotal();
void purchaseItem();
void searchItem();




//! Main function _________________________________________________________

int main () {
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
        cout << "USER MAIN MENU" << endl;
        do {
            cout << "1. Add Item\n" 
                << "2. Print Inventory\n"
                << "3. Purchase Item\n"
                << "4. Calculate Total\n"
                << "5. Exit\n"
                << endl;
            cout << "Enter your choice (1-5): ";
            cin >> choice;
            cin.ignore();
            cin.clear();

            if (choice < 1 || choice > 5) {
                cout << "OOPS! Invalid choice. Please enter number from 1 to 5" << endl;
            }

        } while (choice < 1 || choice > 5); //repeat until the user enters a valid choice

        // Call the appropriate function based on user input
        switch (choice-1) {
            case ADD_ITEM:
                addItem();
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
            default:
                cout << "OOPS! Invalid choice. Please enter number from 1 to 5" << endl;
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
    Line(50);
    cout << "PRINT INVENTORY" << endl;

    // Open the "feed.dat" file in binary read mode
    ifstream inFile("feed.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read all structures from the file and display in table form
    Item currentItem;

    Line(50);

    cout << setw(20) << left << "Item Name"
         << setw(10) << left << "Qty (bags)"
         << setw(10) << left << "Price/bag"
         << setw(10) << left << "Total" << endl;
    
    Line(50);
    float totalValue = 0;
    while (inFile.read(reinterpret_cast<char*>(&currentItem), sizeof(currentItem))) {
        cout << setw(20) << left << currentItem.item
             << setw(10) << left << currentItem.qty
             << setw(10) << left << currentItem.price
             << setw(10) << left << (currentItem.qty * currentItem.price) << endl;
        totalValue += currentItem.qty * currentItem.price;
    }
    inFile.close();

    Line(50);
    cout << setw(40) << right << "Total Value: " << setw(10) << left << totalValue << endl;
}



// Function to search for an item by name
void searchItem() {
    //Not Needed
}



// Function to purchase an item by name and quantity
void purchaseItem() {
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
    // Open the "feed.dat" file in binary mode for reading
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
