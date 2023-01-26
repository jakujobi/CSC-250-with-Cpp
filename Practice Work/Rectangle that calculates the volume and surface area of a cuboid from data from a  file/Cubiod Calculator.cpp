/*
This program calculates the volume and surface area of a cuboid from data from a file "cuboid numbers.txt" using arrays

The file contains 3 numbers, the length, width and height of the cuboid.

Functions
openFile - opens the file
readData - reads the data from the file using an array
displayData - displays the data
calculateVolume - calculates the volume
calculateSurfaceArea - calculates the surface area


*/

#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"

using namespace std;

// Functions
void openFile(ifstream &file);
void openFile(ifstream &file)
{
    file.open("cuboid numbers.txt");
    if (!file)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void readData(ifstream &file, int data[]);
void readData(ifstream &file, int data[])
{
    for (int i = 0; i < 3; i++)
    {
        file >> data[i];
    }
}


void displayData(int data[]);
void displayData(int data[])
{
    cout << "The length is " << data[0] << endl;
    cout << "The width is " << data[1] << endl;
    cout << "The height is " << data[2] << endl;
}


int calculateVolume(int data[]);
int calculateVolume(int data[])
{
    return data[0] * data[1] * data[2];
}

int calculateSurfaceArea(int data[]);
int calculateSurfaceArea(int data[])
{
    return 2 * (data[0] * data[1] + data[0] * data[2] + data[1] * data[2]);
}

int main()
{
    ifstream file;
    int data[3];

    openFile(file);
    readData(file, data);
    displayData(data);
    cout << "The volume is " << calculateVolume(data) << endl;
    cout << "The surface area is " << calculateSurfaceArea(data) << endl;

    return 0;
}


void openFile(ifstream &file)
{
    file.open("cuboid numbers.txt");
    if (!file)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

