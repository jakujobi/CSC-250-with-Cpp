#include <iostream>
#include <cstring>

using namespace std;

void convertToWords(char* num);

char* ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
//char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
//char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char* elevenToNineteen[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
//char* elevenToNineteen[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

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

void convertToWords(char* num)
{
    int len = strlen(num);

    if (len == 0)
    {
        cout << "empty string" << endl;
        return;
    }
    if (len > 4)
    {
        cout << "Length more than 4 is not supported" << endl;
        return;
    }

    char* singleDigits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    //char* singleDigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Array to store number as a string
    char* numArr[len + 1];

    // Copy the input string to the array
    for (int i = 0; i < len; i++)
    {
        numArr[i] = &num[i];
    }
    numArr[len] = "\\0";

    if (len == 1)
    {
        cout << singleDigits[*numArr[0] - '0'] << endl;
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
            cout << ones[*numArr[i] - '0'] << " thousand ";
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
            if (flag == 1)
            {
                cout << "and ";
                flag = 0;
            }

            cout << ones[*numArr[i] - '0'] << " ";
        }
    }
}
