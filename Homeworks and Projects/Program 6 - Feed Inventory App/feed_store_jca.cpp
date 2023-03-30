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
}


// Asks the user for choice and calls the appropriate function
int getChoice() {
    int choice;

    do {
        //Print the main menu
        Line(16);
        cout << "USER MAIN MENU" << endl;
        do {
            cout << "1. Add Item" 
                << "2. Print Inventory"
                << "3. Purchase Item"
                << "4. Calculate Total"
                << "5. Exit"
                << endl;
            cout << "Enter your choice (1-5): ";
            cin.ignore();
            cin >> choice;
            cin.clear();

            if (choice < 1 || choice > 5) {
                cout << "OOPS! Invalid choice. Please enter number from 1 to 5" << endl;
            }

        } while (choice < 1 || choice > 5); //repeat until the user enters a valid choice

        // Call the appropriate function based on user input
        switch (choice) {
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
    Line(16);


    cout << "\nWith " << MAX_CHAR << " maximum characters,\n"
        << "Enter the item name -->: ";
    cin.getline(newItem.item, MAX_CHAR); //get the item name from the user
    cin.ignore();
    cin.clear();
    cout << newItem.item << " has been added to the inventory." << endl;

    //ask the user for the item quantity
    do {
        cout << "Enter the quantity of bags -->: ";
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
        cout << "Enter the price per bag of the item-->: ";
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

    cout << "Item added successfully!" << endl;

    //ask the user if they want to add another item
    //uses recursive by calling addItem() again
    cout << "Do you want to add another item? (y/n): ";
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


void printInventory() {
    
}


void searchItem() {
    
}


void purchaseItem() {
    
}


void calcTotal() {
    
}
