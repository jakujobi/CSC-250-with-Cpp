/*
I want to write a program which uses different search algorithms to find a number in an array list of numbers.
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//This is the linear search algorithm
//It returns the index location of the value in the array
int linearSearch (int arr[], int size, int value);
int linearSearch (int arr[], int size, int value)
{
    int index = 0;  //used as a subscript to search array
    int position = -1;  //to record position of search value
    bool found = false;  //flag to indicate if the value was found

    while (index < size && !found)
    {
        if (arr[index] == value)  //if the value is found
        {
            found = true;  //set the flag
            position = index;  //record the value's subscript
        }
        index++;  //go to the next element
    }
    return position;  //return the position, or -1
}


//This is the binary search algorithm
//It returns the index location of the value in the array
int binarySearch (int arr[], int size, int value);
int binarySearch (int arr[], int size, int value)
{
    int first = 0;  //first array element (0)
    int last = size - 1;  //last array element (size - 1)
    int middle;  //midpoint of search (first + last) / 2
    int position = -1;  //position of search value (if found)
    bool found = false;  //flag to indicate if the value was found


    //search for the value
    while (!found && first <= last)
    {
        middle = (first + last) / 2;  //calculate midpoint

        if (arr[middle] == value)  //if value is found at mid
        {
            found = true;
            position = middle;
        }

        else if (arr[middle] > value)  //if value is in lower half
        {
            last = middle - 1;
        }

        else  //if value is in upper half
        {
            first = middle + 1;  //if value is in upper half
        }
    }
    return position;
}


//Very simple code to print the array
void printArray (int arr[], int size);
void printArray (int arr[], int size)
{
    int i;  //counter
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 5;

    cout << "The array is: ";
    printArray(arr, size);

    cout << "The value is: " << value << endl;

    cout << "The index location of the value in the array is: " << linearSearch(arr, size, value) << endl;

    cout << "The index location of the value in the array is: " << binarySearch(arr, size, value) << endl;

    return 0;
}