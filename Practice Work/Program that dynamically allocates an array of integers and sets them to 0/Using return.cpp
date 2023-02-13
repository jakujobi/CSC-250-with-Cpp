#include <iostream>
using namespace std;

// This function dynamically allocates an array of integers
int* allocateArray(int size);
int* allocateArray(int size)
{
    int* array = new int[size];

    //Loop through the array and set each element to 0
    for (int i = 0; i < size; i++)
    {
        array[i] = 0; // Set each element to 0
    }

    return array;
}

int main()
{
    int size;   // The size of the array

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    // Call the allocateArray function
    int* arr = allocateArray(size);

    // Display the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    // Display the success message
    cout << "The array has been allocated and set to 0." << endl;

    // Free the memory
    delete[] arr;

    return 0;
}


//This function swaps the values of two variables p and q
//taking the address of the variables as arguments
void swap(double &p, double &q)
{
    // temp is a local variable to temorary store the value of p
    double temp = p; 
    
    p = q;
    q = temp;
}

//This function swaps the values of two variables p and q
void swap(double *p, double *q);
void swap(double *p, double *q)
{
    double temp = *p; // temp is a local variable to temorary store the value of p
    *p = *q;
    *q = temp;
}