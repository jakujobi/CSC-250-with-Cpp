#include <iostream>
#include <cstring>

using namespace std;



const char* const ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
//char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

const char* const tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
//char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const char* const elevenToNineteen[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
//char* elevenToNineteen[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};


// This function prints a given number in words
// The number is assumed to be less than 9999
void convertToWords(char* num);
void convertToWords(char* num)
{
    // Get the number of digits in the given number using the length of the string
    int len = strlen(num);

    // If there are no digits in the given number, print an error message
    if (len == 0)
    {
        cout << "\nError\nUH OH! It seems there is nothing in the input " << endl;
        return;
    }
    if (len > 4)
    {
        cout << "\nError\nOOPS! Please put a number less than 9999" << endl;
        return;
    }

    // Tries to use this array of strings for single digit numbers
    // but instead used the ones array
    //char* singleDigits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    //char* singleDigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Array to store number as a string
    char* numArr[len + 1];

    // Copy the input string to the array
    for (int i = 0; i < len; i++)
    {
        // Convert the character to integer
        numArr[i] = &num[i];
    }

    // Add a null character to the end of the array
    numArr[len] = "\\0";

    // If the number is a single digit, print the corresponding word from the ones array
    if (len == 1)
    {
        cout << ones[*numArr[0] - '0'] << endl;
        return;
    }

    // Initialize a flag variable
    int flag = 0;

    // Loop through the input string
    for (int i = 0; i < len; i++)
    {
        // If the first digit is a zero, skip it
        if (*numArr[i] == '0')
        {
            flag = 1;
            continue;
        }

        // Print thousands place
        if ((len - i) == 4)
        {
            cout << ones[*numArr[i] - '0'] << " thousand, ";
        }

        // Print hundreds place
        else if ((len - i) == 3)
        {
            cout << ones[*numArr[i] - '0'] << " hundred ";
        }

        // Print tens place
        else if ((len - i) == 2)
        {
            // If the current digit is a 1, print the corresponding teens word
            if (*numArr[i] == '1')
            {
                // Print the teens word
                cout << elevenToNineteen[*numArr[i + 1] - '0' - 1] << endl;
                return;
            }

            // Print the tens word
            else
            {
                cout << tens[*numArr[i] - '0'] << " ";
            }
        }

        // Print ones place
        else
        {
            // If the previous digit was a zero, print "and"
            if (flag == 1)  // If the previous digit was a zero, print "and"
            {
                cout << "and ";
                flag = 0; // Reset the flag
            }

            cout << ones[*numArr[i] - '0'] << " ";
        }
    }
}







int main()
{
    int num;
    char numString[100];

    cout << "Enter an integer: ";
    cin >> num;

    // Convert integer to C-string
    sprintf(numString, "%d", num);

    // Call function to convert to words
    convertToWords(numString);

    return 0;
}