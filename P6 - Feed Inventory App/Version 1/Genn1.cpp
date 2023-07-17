#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

// Structure definition
struct Item {
    char item[50];
    int qty;
    float price;
};

// Function to add a new item to the inventory
void addItem() {
    // Create a new Item structure and get input from user
    Item newItem;
    cout << "Enter the name of the item: ";
    cin.getline(newItem.item, 50);
    cout << "Enter the quantity (in bags): ";
    cin >> newItem.qty;
    cout << "Enter the price per bag: ";
    cin >> newItem.price;
    cin.ignore(); // Ignore newline character

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
}

// Function to print the inventory in table form
void printInventory() {
    // Open the "feed.dat" file in binary read mode
    ifstream inFile("feed.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read all structures from the file and display in table form
    Item currentItem;
    cout << setw(20) << left << "Item Name"
         << setw(10) << left << "Qty (bags)"
         << setw(10) << left << "Price/bag"
         << setw(10) << left << "Total" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    float totalValue = 0;
    while (inFile.read(reinterpret_cast<char*>(&currentItem), sizeof(currentItem))) {
        cout << setw(20) << left << currentItem.item
             << setw(10) << left << currentItem.qty
             << setw(10) << left << currentItem.price
             << setw(10) << left << (currentItem.qty * currentItem.price) << endl;
        totalValue += currentItem.qty * currentItem.price;
    }
    inFile.close();

    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    cout << setw(40) << right << "Total Value: " << setw(10) << left << totalValue << endl;
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
    while (file.read(reinterpret_cast<char*>(&item), sizeof(Item))) {
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
        file.seekp(static_cast<int>(file.tellg()) - static_cast<int>(sizeof(Item)), ios::beg);
        file.write(reinterpret_cast<char*>(&item), sizeof(Item));

        cout << "Purchase successful." << endl;
        cout << "Total price: $" << purchasePrice << endl;
    }
    else {
        cout << "Item not found." << endl;
    }

    // Close the file
    file.close();
}



// Function to calculate the total value of the items on hand
void calculateTotalValue() {
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



// Function to display the operations menu and handle user input
void displayMenu() {
int choice;
    do {
        // Display the menu options
        cout << endl;
        cout << "Feed Store Inventory" << endl;
        cout << "---------------------" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Print the information for all items, in table form" << endl;
        cout << "3. Purchase an item" << endl;
        cout << "4. Calculate and display the total value of the items on hand" << endl;
        cout << "5. Exit" << endl;

        // Get user input
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Call the appropriate function based on user input
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                printInventory();
                break;
            case 3:
                purchaseItem();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
}



int main() {
// Display the operations menu and handle user input
displayMenu();
return 0;
}