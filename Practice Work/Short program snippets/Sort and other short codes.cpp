//This is a code snippet for selection sort

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void selectionSort (int arr[], int size);
void selectionSort (int arr[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


//Very simple code to print the array
void printArray (int arr[], int size);
void printArray (int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//This is version 2 for selection sort
void selectionSortv2 (int arr[], int size);
void selectionSortv2 (int arr[], int size)
{
    int small_location;  //location of the smallest element

    //outer loop to do the passes
    for (int wall = 0; wall < size - 1; wall++)
    {
        small_location = wall;

        int i = wall + 1;
        while (i < size)
        {
            if (arr[i] < arr[small_location])
            {
                small_location = i;
            }
            i++;
        }

        // //inner loop to find the smallest element
        // for (int i = wall + 1; i < size; i++)
        // {
        //     if (arr[i] < arr[small_location])
        //     {
        //         small_location = i;
        //     }
        // }

        //swap the smallest element with the element at the wall
        int temp = arr[wall];
        arr[wall] = arr[small_location];
        arr[small_location] = temp;
    }
}


//This is for bubble sort
void bubbleSort (int arr[], int size);
void bubbleSort (int arr[], int size)
{
    int temp; //temporary variable to store the value of the element

    //outer loop to do the passes
    for (int i = 0; i < size - 1; i++)
    {
        //inner loop to do the comparisons
        for (int j = 0; j < size - i - 1; j++)
        {
            //compare the adjacent elements and swap them if they are not in order
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


//This is for insertion sort
void insertionSort (int arr[], int size);
void insertionSort (int arr[], int size)
{
    int i, j, temp;

    //outer loop to do the passes
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;

        //inner loop to do the comparisons
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


//This is for quick sort
void quickSort (int arr[], int first, int last);
void quickSort (int arr[], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }
}


//This function swaps the elements
void swap (int *a, int *b);
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



//!_______________________________________________________________________________________________________________________________________________________________________________________
//! MAIN FUNCTION
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);

    //This is for selection sort
    selectionSort(arr, size);

    
    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}
