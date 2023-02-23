#include <iostream> // for cout, cin, endl
#include <cstring> // for strlen, strcpy, strcmp

using namespace std;

//THE ARRAY OF STRINGS FOR THE WORDS
// The array of strings for the ones place
const char* const ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
//char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// The array of strings for the tens place
const char* const tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
//char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// The array of strings for the teens
const char* const elevenToNineteen[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
//char* elevenToNineteen[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};


// THE FUNCTIONS

// This function will get the input from the user
void getInput(char* date);
void getInput(char* date)
{
    // Ask the user to enter a date in the format MM/DD/YYYY
    cout << "Enter a date in the format MM/DD/YYYY: ";
    cin.getline(date, 11);
}


// Prints the error message which will
//Then be followed by the reason why the date is invalid contained in the function checkDateFormat
void printError ();
void printError ()
{
    cout << "Error\n  with dateThe date is invalid\nPlease make sure that the date is in the format MM/DD/YYYY\n";
}


int checkDateFormat(char* date)
{
    // Check if the input string has length 10
    if (strlen(date) != 10)
    {
        printError(); //Prints the error message
        cout << "It seems that there are more characters than needed\n";
        return 1;
    }

    // Check if the first two characters are digits representing a valid month
    int month = stoi(string(date).substr(0, 2));
    if (month < 1 || month > 12)
    {
        printError();   //Prints the error message
        cout << "The month must be between 1 and 12\n";
        return 1;
    }

    // Check if the third character is a forward slash
    if (date[2] != '/')
    {
        printError();   //Prints the error message
        cout << "The third character is not a forward slash\n";
        return 1;
    }

    // Check if the fourth and fifth characters are digits representing a valid day
    int day = stoi(string(date).substr(3, 2));
    if (day < 1 || day > 31)
    {
        printError();   //Prints the error message
        cout << "The day must be between 1 and 31\n";
        return 1;
    }

    // Check if the sixth character is a forward slash
    if (date[5] != '/')
    {
        printError(); //Prints the error message
        cout << "The sixth character is not a forward slash\n";
        return 1;
    }

    // Check if the last four characters are digits representing a valid year
    int year = stoi(string(date).substr(6, 4));
    if (year < 0 || year > 9999)
    {
        printError(); //Prints the error message
        cout << "The year must be between 0 and 9999\n";
        return 1;
    }

    //check for invalid days of february
    // Just in case
    // Though it might not work for 29 on non-leap years
    if (month == 2 && day > 29)
    {
        cout << "\nError!\nFebruary only has 29 days in a leap year\n";
        return 1;
    }

    //check for invalid days of months with 30 days
    //Like April, June, September, and November
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            cout << "\nError!\nThis month only has 30 days\n";
            return 1;
        }
    }

    // If all checks pass, then return true
    //Woohoo!
    cout << "Good Job, The date is valid\n";
    return 0;
}




// This function prints a given number in words
// The number is assumed to be less than 9999
void convertNumToWords(int num);
void convertNumToWords(int num)
{
    // Get the number of digits in the given number using the length of the string
    //int lengthOfNum= strlen(num);
    int lengthOfNum = to_string(num).length();

    // If there are no digits in the given number, print an error message
    if (lengthOfNum== 0)
    {
        cout << "\nError\nUH OH! It seems there is nothing in the input " << endl;
        return;
    }
    if (lengthOfNum> 4)
    {
        cout << "\nError\nOOPS! Please put a number less than 9999" << endl;
        return;
    }

    // Tries to use this array of strings for single digit numbers
    // but instead used the ones array
    //char* singleDigits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    //char* singleDigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Array to store number as a string
    char* numArr[lengthOfNum+ 1];

    // Copy the input string to the array
    for (int i = 0; i < lengthOfNum; i++)
    {
        // Convert the character to integer
        numArr[i] = &num[i];
    }

    // Add a null character to the end of the array
    numArr[lengthOfNum] = "\\0";

    // If the number is a single digit, print the corresponding word from the ones array
    if (lengthOfNum== 1)
    {
        // Print the corresponding word from the ones array
        cout << ones[*numArr[0] - '0'] << endl;
        return;
    }

    // Initialize a flag variable
    int flag = 0;

    // Loop through the input string
    for (int i = 0; i < lengthOfNum; i++)
    {
        // If the digit is a zero, skip it
        if (*numArr[i] == '0')
        {
            flag = 1;
            continue;
        }

        // Print thousands place
        if ((lengthOfNum- i) == 4)
        {
            // IF there are 4 digits in the number
            // print the corresponding word from the ones array and "thousand"
            cout << ones[*numArr[i] - '0'] << " thousand, ";
        }

        // Print hundreds place
        else if ((lengthOfNum- i) == 3)
        {
            // IF there are 3 digits in the number
            // print the corresponding word from the ones array and "hundred"
            cout << ones[*numArr[i] - '0'] << " hundred ";
        }

        // Print tens place
        else if ((lengthOfNum- i) == 2)
        {
            // If the current digit is a 1, print the corresponding teens word
            if (*numArr[i] == '1')
            {
                // If the first digit is a 1
                //Print the corresponding teens word
                cout << elevenToNineteen[*numArr[i + 1] - '0' - 1] << endl;
                return;
            }

            // Print the tens word
            else
            {
                // if the number isnt a teens number
                // print the corresponding tens word
                cout << tens[*numArr[i] - '0'] << " ";
            }
        }

        // Print ones place
        else
        {
            // If the previous digit was a zero, print "and"
            if (flag == 1)  // If the previous digit was a zero, print "and"
            {
                // add the word "and" to the output
                cout << "and ";
                flag = 0; // Reset the flag
            }

            cout << ones[*numArr[i] - '0'] << " ";
        }
    }
}



// This function splits the date into its parts
void splitDateIntoParts(char* date);
void splitDateIntoParts(char* date)
{
    // Get the number of digits in the given number using the length of the string
    //then using strtok to get the month, day, and year
    //then using stoi to convert the month, day, and year to ints
    //I got the strtok function description from: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    int month = stoi(strtok(date, "/")); // Get the month
    int day = stoi(strtok(NULL, "/")); // Get the day
    int year = stoi(strtok(NULL, "/")); // Get the year

    // Print the date in words

    // print the month in words
    cout << months[month] << " ";

    // print the day in words
    convertNumToWords(day);
    if (day >= 11 && day <= 19)
    {
        cout << "th";
    }
    else if (day % 10 == 1)
    {
        cout << ones[day] << "st";
    }
    else if (day % 10 == 2)
    {
        cout << ones[day] << "nd";
    }
    else if (day % 10 == 3)
    {
        cout << ones[day] << "rd";
    }
    else
    {
        cout << ones[day] << "th";
    }

    // print the year in words
    cout << " " << ones[year / 1000] << " thousand, ";
    
    cout << endl;
}

// This function prints the date in words
// The date is assumed to be in the format mm/dd/yyyy
void printDateInWords(int month, int day, int year);
void printDateInWords(int month, int day, int year)
{
    // To print the month in words
    cout << months[month] << " " << ones[day] << " ";

    // To print the day in words
    if (day >= 11 && day <= 19)
    {
        cout << "th";
    }
    else if (day % 10 == 1)
    {
        cout << "st";
    }
    else if (day % 10 == 2)
    {
        cout << "nd";
    }
    else if (day % 10 == 3)
    {
        cout << "rd";
    }
    else
    {
        cout << "th";
    }

    cout << ", " << year << endl;
}






int main()
{
    // Declare variables
    int num;    // Integer to be converted to words
    char date[11]; // C-string to store the date

    // Convert date to words
    convertToWords(date);
    
    char numString[100];    // C-string to store the integer

    // Print the program welcome message
    cout << "Welcome to the Number to Words Converter!\n";

    //A loop that asks the user for input and checks if the input is valid using the checkDate function
    //If the input is valid, the loop breaks
    //If the input is invalid, the loop continues
    while (true)
    {
        // Get user input
        getInput(date);


        // Convert integer to C-string
        sprintf(numString, "%d", num);

        // Call the function to convert to words
        convertToWords(numString);

        // Ask the user if they want to continue
        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;

        // If the user does not want to continue, break the loop
        if (choice == 'n' || choice == 'N')
        {
            break;
        }
    }



    // Ask our user for input
    cout << "Enter an integer: ";
    cin >> num;

    // Convert integer to C-string
    sprintf(numString, "%d", num);

    // Call the function to convert to words
    convertToWords(numString);

    return 0;
}