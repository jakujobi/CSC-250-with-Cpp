#include <iostream>
#include <string>

using namespace std;

// A function that prints a given number in words
void convertToWords(int num)
{
    // Array of strings for single digit numbers
    string singleDigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Array of strings for two digit numbers from 10 to 19
    string twoDigits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    // Array of strings for multiples of ten
    string tensMultiples[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    // Array of strings for powers of ten
    string tensPower[] = {"hundred", "thousand"};

    // Convert the number to a string
    string numStr = to_string(num);

    // Get the number of digits in the given number
    int len = numStr.length();

    // Base cases
    if (len == 0)
    {
        cerr << "empty string" << endl;
        return;
    }

    if (len > 4)
    {
        cerr << "Length more than 4 is not supported" << endl;
        return;
    }

    // Used for debugging purpose only
    cout << "\n" << num << ": ";

    // For single digit number
    if (len == 1)
    {
        cout << singleDigits[num] << endl;
        return;
    }

    // Iterate while there are still digits in the string
    int i = 0;
    while (i < len)
    {
        // Code path for first 2 digits
        if (len >= 3)
        {
            if (numStr[i] - '0' != 0)
            {
                cout << singleDigits[numStr[i] - '0'] << " ";
                cout << tensPower[len - 3] << " "; // here len can be 3 or 4
            }
            len--;
        }

        // Code path for last 2 digits
        else
        {
            /* Need to explicitly handle 10-19. Sum of the two digits is used as index of "two_digits"
            array of strings */
            if (numStr[i] == '1')
            {
                int sum = numStr[i] - '0' + numStr[i + 1] - '0';
                cout << twoDigits[sum - 10] << endl;
                return;
            }

            // Need to explicitly handle 20
            else if (numStr[i] == '2' && numStr[i + 1] == '0')
            {
                cout << "twenty" << endl;
                return;
            }

            // Rest of the two digit numbers i.e., 21 to 99
            else
            {
                int j = numStr[i] - '0';

                string tm = j ? tensMultiples[j] : "";
                if (tm != "")
                {
                    cout << tm << " ";
                }

                i++;

                if (numStr[i] != '0')
                {
                    cout << singleDigits[numStr[i] - '0'] << endl;
                }
            }
        }

        i++;

    }
}


//This function prinnts the single digit number in words
void printSingleDigit(char digit)
{
    switch(digit)
    {
        case '0':
            cout << "zero";
            break;
        case '1':
            cout << "one";
            break;
        case '2':
            cout << "two";
            break;
        case '3':
            cout << "three";
            break;
        case '4':
            cout << "four";
            break;
        case '5':
            cout << "five";
            break;
        case '6':
            cout << "six";
            break;
        case '7':
            cout << "seven";
            break;
        case '8':
            cout << "eight";
            break;
        case '9':
            cout << "nine";
            break;
        default:
            cerr << "Invalid digit";
            break;
    }
}


void printTwoDigits(char* num)
{
    if (*num == '0')
    {
        return;
    }

    else if (*num == '1')
    {
        int sum = *num - '0' + *(num + 1) - '0';

        switch(sum)
        {
            case 10:
                cout << "ten";
                break;
            case 11:
                cout << "eleven";
                break;
            case 12:
                cout << "twelve";
                break;
            case 13:
                cout << "thirteen";
                break;
            case 14:
                cout << "fourteen";
                break;
            case 15:
                cout << "fifteen";
                break;
            case 16:
                cout << "sixteen";
                break;
            case 17:
                cout << "seventeen";
                break;
            case 18:
                cout << "eighteen";
                break;
            case 19:
                cout << "nineteen";
                break;
            default:
                cerr << "Invalid two-digit number";
                break;
        }
    }

    else 
    {
        switch(*num)
        {
            case '2':
                cout << "twenty";
                break;
            case '3':
                cout << "thirty";
                break;
            case '4':
                cout << "forty";
                break;
            case '5':
                cout << "fifty";
                break;
            case '6':
                cout << "sixty";
                break;
            case '7':
                cout << "seventy";
                break;
            case '8':
                cout << "eighty";
                break;
            case '9':
                cout << "ninety";
                break;
            default:
                cerr << "Invalid digit";
                break;
        }
        
        ++num;
        printSingleDigit(*num);
    }
}

void printThreeDigits(char* num)
{
    printSingleDigit(*num);

    if (*num != '0')
    {
        cout << " hundred ";
    }
    
    ++num; // increment pointer to point to next digit
    printTwoDigits(num);
}

void printFourDigits(char* num)
{
    printSingleDigit(*num);

    if (*num != '0')
    {
        cout << " thousand ";
    }
    
    ++num;
    printThreeDigits(num);
}







// Driver program to test above function
int main() {
    convertToWords(9923);
    convertToWords(523);
    convertToWords(89);
   
