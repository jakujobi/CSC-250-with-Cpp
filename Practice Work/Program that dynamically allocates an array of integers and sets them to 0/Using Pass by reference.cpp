#include <iostream>
using namespace std;

void allocateArray(int size, int*& array)
{
    // Allocate the array
    array = new int[size];

    // Set the array to 0
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

//Main function to test the allocateArray function
int main()
{

    int size; // The size of the array

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr; // Pointer to the array

    // Call the allocateArray function
    allocateArray(size, arr);

    // Display the array
    cout << "The array has been allocated and set to 0." << endl;

    // Free the memory
    delete[] arr;

    return 0;
}
