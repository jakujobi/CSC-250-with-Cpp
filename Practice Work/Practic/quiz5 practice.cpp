#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
//Question


enum Color {RED, YELLOW, BLUE};

void printColorDescription (Color tint){
    switch (tint) {
        case RED:
            cout << "Red";
            break;
        case YELLOW:
            cout << "Yellow";
            break;
        case BLUE:
            cout << "Blue";
            break;
        default:
            cout << "Unknown";
            break;
    }
}

struct Item {
    string desc;
    Color hue;
    float cost;
};

//Write a definition statement for an array of 10 structures named Shirts.
//The same statement should initialize the first 3 structures in the array with the data below.
//Item 1: "Small - S", Color: RED, Cost: 3.00
//Item 2: "Medium - M", Color: YELLOW, Cost: 5.00
//Item 3: "Large - L", Color: BLUE, Cost: 7.00


//Prints the menu in a table format.
//table format: Description, Color, Cost

void printShirt( Item Shirts[]);

int main (){
    Item Shirts[10] = {{"Small - S", RED, 3.00}, {"Medium - M", YELLOW, 5.00}, {"Large - L", BLUE, 7.00}};

    cout << "HIYAA, JackRabbit!\nWelcome to the SDSU Shirt Sales program!" << endl;
    printShirt(Shirts);
    return 0;
} 

void printShirt( Item Shirts[]){
    cout << "Description, Color, Cost" << endl;
    for (int i = 0; i < 10; i++){
        cout << setw(15) << Shirts[i].desc << " | ";
        printColorDescription (Shirts[i].hue);
        cout << " | " << fixed << setw(4) << setprecision(2) << Shirts[i].cost << endl;
    }
}