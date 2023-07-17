#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ENUMERATED TYPES
enum Size { S, M, L, XL, XXL };

// STRUCTURES

struct Shirt
{
    string name; // name of the shirt
    float cost; // cost of the shirt
    int qty[5]; // quantity of shirts for each size
};

// GLOBAL VARIABLES

const int NUM_SHIRTS = 5; // the number of shirts in the vendor's menu
Shirt shirts[NUM_SHIRTS]; // array of structures that stores the vendor's menu

// FUNCTIONS

// This function reads the vendor's menu from the shirts.txt file and initializes the shirts array of structures
void readMenu();
void readMenu()
{
    ifstream inputFile("shirts.txt");
    if (!inputFile)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        getline(inputFile, shirts[i].name);
        inputFile >> shirts[i].cost;
        for (int j = 0; j < 5; j++)
        {
            shirts[i].qty[j] = 0;
        }
        inputFile.ignore();
    }

    inputFile.close();
}

// This function displays the vendor's menu in a table format
void displayMenu();
void displayMenu()
{
    cout << "Vendor's Menu:" << endl;
    cout << "--------------" << endl;
    cout << "No.  Name                            Cost       S  M  L XL XXL  Total" << endl;

    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        cout << i + 1 << ".   ";
        cout << left << setw(32) << shirts[i].name << " ";
        cout << "$" << fixed << setprecision(2) << shirts[i].cost << "  ";
        for (int j = 0; j < 5; j++)
        {
            cout << shirts[i].qty[j] << "  ";
        }
        float total = shirts[i].cost * (shirts[i].qty[0] + shirts[i].qty[1] + shirts[i].qty[2] + shirts[i].qty[3] + shirts[i].qty[4]);
        cout << "$" << fixed << setprecision(2) << total << endl;
    }
}

// This function gets the user's choice (order, checkout, or exit)
char getChoice();
char getChoice()
{
    char choice;
    cout << endl;
    cout << "Enter your choice (O)rder, (C)heckout, or (E)xit: ";
    cin >> choice;
    choice = toupper(choice);
    while (choice != 'O' && choice != 'C' && choice != 'E')
    {
        cout << "Invalid choice. Please enter (O)rder, (C)heckout, or (E)xit: ";
        cin >> choice;
        choice = toupper(choice);
    }
    cin.ignore(); // ignore the newline character
    return choice;
}

// This function gets the user's order (size and quantity)
void getOrder(Size& size, int& quantity);
void getOrder(Size& size, int& quantity)
{
    cout << "Enter the shirt size (S, M, L, XL, XXL): ";
    string sizeStr;
    cin >> sizeStr;
    while (sizeStr != "S" && sizeStr != "M" && sizeStr != "L" && sizeStr != "XL" && sizeStr != "XXL")
    {
        cout << "Invalid size. Please enter S, M, L, XL, or XXL: ";
        cin >> sizeStr;
    }
    if (sizeStr == "S")
    {
        size = S;
    }
    else if (sizeStr == "M")
    {
        size = M;
    }
    else if (sizeStr == "L")
    {
        size = L;
    }
    else if (sizeStr == "XL")
    {
        size = XL;
    }
    else if (sizeStr == "XXL")
    {
        size = XXL;
    }

    cout << "Enter the quantity: ";
    cin >> quantity;
    while (quantity < 0)
    {
        cout << "Invalid quantity. Please enter a positive number: ";
        cin >> quantity;
    }
}

// This function adds the user's order to the quantity of the selected shirt in the menu
void addOrder(Size size, int quantity);
void addOrder(Size size, int quantity)
{
    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        if (size == S)
        {
            shirts[i].qty[0] += quantity;
        }
        else if (size == M)
        {
            shirts[i].qty[1] += quantity;
        }
        else if (size == L)
        {
            shirts[i].qty[2] += quantity;
        }
        else if (size == XL)
        {
            shirts[i].qty[3] += quantity;
        }
        else if (size == XXL)
        {
            shirts[i].qty[4] += quantity;
        }
    }
}

// This function calculates the total cost of the order, including tax
float calculateTotal();
float calculateTotal()
{
    float subtotal = 0;
    for (int i = 0; i < NUM_SHIRTS; i++)
    {
        subtotal += shirts[i].cost * (shirts[i].qty[0] + shirts[i].qty[1] + shirts[i].qty[2] + shirts[i].qty[3] + shirts[i].qty[4]);
    }
    float tax = subtotal * 0.065;
    float total = subtotal + tax;
    return total;
}

// MAIN FUNCTION

int main()
{
    readMenu();

    char choice;
    do
    {
        displayMenu();
        choice = getChoice();

        if (choice == 'O')
        {
            Size size;
            int quantity;
            getOrder(size, quantity);
            addOrder(size, quantity);
        }
        else if (choice == 'C')
        {
            float total = calculateTotal();
            cout << "Your total is: $" << fixed << setprecision(2) << total << endl;
            for (int i = 0; i < NUM_SHIRTS; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    shirts[i].qty[j] = 0;
                }
            }
        }

    } while (choice != 'E');

    return 0;
}
