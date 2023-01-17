//Add the main libraries and add a description on what they do and the functions they have

#include <iostream>
// this library is used for input and output
// it has functions like cout and cin which are used to print and read data

#include <string>
// this library is used for strings
// it has functions like getline which is used to read a string

#include <fstream>
// this library is used for files
// it has functions like open and close which are used to open and close files

#include <vector>
// this library is used for vectors

#include <algorithm>
// this library is used for sorting

#include <iomanip>
// this library is used for formatting
// it has functions like setw which is used to set the width of a column

#include <numeric>
// this library is used for mathematics

#include <cmath>
// this library is used for mathematics

#include <cstdlib>
// this library is used for system
// it has functions like system which is used to clear the screen

using namespace std;
// this is used to avoid writing std:: before every function


//functions to input, process and output data

void getData (float & length, float & width, float & height); // function call

void getData (float & length, float & width, float & height)
{
    // this function is used to get the data from the user
    cout << "Enter the length of the box: ";
    cin >> length;
    cout << "Enter the width of the box: ";
    cin >> width;
    cout << "Enter the height of the box: ";
    cin >> height;
}


void calcVolume (float length, float width, float height, float & volume);

void calcVolume (float length, float width, float height, float & volume)
{
    // this function is used to calculate the volume of the box
    volume = width * height * length;
    cout << "The volume is: " << volume << endl;
}


void calcSurfaceArea (float length, float width, float height, float & surfaceArea);

void calcSurfaceArea (float length, float width, float height, float & surfaceArea)
{
    // this function is used to calculate the surface area of the box
    surfaceArea = 2 * (length * width + length * height + width * height);

    cout << "The surface area is: " << surfaceArea << endl;
}


void printData (float length, float width, float height);

void printData (float length, float width, float height)
{
    // this function is used to print the data
    cout << "The length of the box is: " << length << endl;

    cout << "The width of the box is: " << width << endl;

    cout << "The height of the box is: " << height << endl;
}



int main()
{
    // this is the main function

    float length, width, height, volume, surfaceArea;

    getData(length, width, height);
    
    cout << "\n\nResults\n";

    printData(length, width, height);
    
    cout << "\n";

    calcSurfaceArea(length, width, height, surfaceArea);

    calcVolume(length, width, height, volume);

    cout << "Thank You for using this program" << endl;

    return 0;
}

