#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

// int main()
// {
//     const int ROWS = 4;
// const int COLS = 6;
// double values[ROWS][COLS];

// int num = 0;

// //print the array
// for (int row = 0; row < ROWS; row++)
// {
//     for (int col = 0; col < COLS; col++)
//     {
//         num++;
//     }
// }

// std::cout << num << std::endl;

// return 0;
// }



// int main()
// {
// const int ROWS = 7;
// const int COLS = 5;
// int data[ROWS][COLS] = { {24, 55}, {34, 72}, {49} };
// cout << data[0][2];
// }



/*
Write a function that calculates the totals of the rows in a 2D array with 5 columns. 
Store the row totals into a separate 1D array.
Pass both arrays into the function along with the number of rows in the 2D array.
*/

// void calculateRowTotals(int rows, int columns, int main2DArray[][5], int rowTotals[]);
// void calculateRowTotals(int rows, int columns, int main2DArray[][5], int rowTotals[])
// {
//     int rowSum = 0; // used to store the sum of each row

//     for (int i = 0; i < rows; i++)
//     {
//         rowSum = 0; // reset the rowSum to 0 for each row
//         for (int j = 0; j < columns; j++)
//         {
//             rowSum += main2DArray[i][j];  // increments the rowSum by the value in the 2D array
//         }

//         rowTotals[i] = rowSum;  // stores the rowSum into the rowTotals array
//     }
// }
// //The function call is:
// //calculateRowTotals(3, 5, twoDArray, rowTotals);

// int main() {
//     int twoDArray[3][5] = { {1, 2, 3, 4, 5},
//                             {6, 7, 8, 9, 10},
//                             {11, 12, 13, 14, 15}};
//     int rowTotals[3];
//     calculateRowTotals(3, 5, twoDArray, rowTotals);

//     // print the rowTotals array
//     for (int i = 0; i < 3; i++)
//     {
//         cout << "Row" << i + 1 << " total is: " << rowTotals[i] << endl;
//     }


//     return 0;
// }


// const int ROWS = 2;
// const int COLS = 3;

// int main()
// {
//     float array[ROWS][COLS] = { {3.3 , 2.2, 1.1},
//                                 {31.5, 6.8} };


//     cout << fixed << setprecision(1);

//     for (int row = 0; row < ROWS; row++)
//     {
//         for (int col = 0; col < COLS; col++)
//         {
//             cout << setw(5) << array[row][col];
//         }
//         cout << endl;
//     }
    
// }

// int main ()
// {
// // float x = 3.75;
// // float * ptr = &x;
// // cout << ptr;

// const int SIZE = 7;
// int data[SIZE] = {24, 55, 34, 72, 49};
// cout << *(data+2);

// return 0;
// }




// // The following function accepts a pointer to a C-string as an argument.
// //The function should count the number of alphabetic characters in the string and return that number.
// int countChars (char str[])
// {
//    int count = 0;   // To hold the number of characters
//    int loc = 0; // To hold the array subscript

//    // Count the number of alphabetic characters in str.
//    while (str[loc] != '\0')
//    {
//         // if (str[loc] >= 'A' && str[loc] <= 'Z' || str[loc] >= 'a' && str[loc] <= 'z')
//         if (isalpha(str[loc]))
//         {
//             count++;
//         }
//         loc++;
//    }
//    return count;
// }

// int main ()
// {
//     char str[] = "14AGT23";
//     cout << countChars(str);
//     return 0;
// }



// int main ()
// {
//     const int SIZE = 21;

//     char name[SIZE];

//     int s = 0;

//     strcpy (name, "Janis");

//     s = strlen(name);

//     cout << s;
// }


// int main ()
// {
//     const int SIZE = 21;

//    // char name[SIZE];

//     // int s = 0;
//     // strcpy (name, "Janis");
//     // s = strlen(name);

	
	
	
	
// string name;
// int s = 0;
// name = "Janis";
// s = strlen(name);

//     cout << s;
//     return 0;
// }



// int main ()
// {
//     int n = 4, m = 2;
//     cout << n << " " << m << endl;
    
//     int *p = &m;
//     *p = (*p) + 3;

//     p = &n;
//     *p = n * m;

//     cout << n << " " << m << endl;
//     return 0;
// }


// int main ()
// {
//     int array[5] = {1, 2, 3, 4, 5};

//     if(&array[1] < &array[2])
//     {
//         cout << "true";
//     }
//     else
//     {
//         cout << "false";
//     }
//     return 0;
// }

//Write a function that's dynamically allocates an array of decimal values and returns the arrays address. The array size is passed into the function. In the function validate size returning nullptr if size is <= 0. You may use a reference parameter or return value for the array's address.

double *dynamic_array(int size)
{
    if (size <= 0)
    {
        return nullptr;
    }
    else
    {
        double *array = new double[size];
        return array;
    }
}