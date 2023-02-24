

//BUGS
/*BUG 1: The program does not print the error message when the date is invalid
*/

/*BUG 2: The program does not print the error message when the date is invalid

Error Message
{  
    Welcome to the Number to Words Converter!
    Enter a date in the format MM/DD/YYYY: 02/22/2023
    Good Job, The date is valid
    Error
    The date you entered is invalid. Please try again.
    Good Job, The date is valid
    Error
}
*/


/* List of functions in the program
void getDate(char* date);
void printError();
int checkDateFormat(char* date);
void printDateIntoWords(char* date);
void convertDayToWords(int day);
void convertNumToWords(int num);
*/


#include <iostream> // for cout, cin, endl
#include <cstring> // for strlen, strcpy, strcmp

using namespace std;

//THE ARRAY OF STRINGS FOR THE WORDS
// The array of strings for the ones place
const char* const ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

// The array of strings for the ones place
const char* const oneths[] = {"", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth"};

// The array of strings for the tens place
const char* const tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

// The array of strings for the teens
const char* const elevenToNineteen[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

// The array of strings for the months
const char* const months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


// THE FUNCTIONS

// This function will get the input from the user
void getDate(char* date);
void getDate(char* date)
{
    //Clear the input buffer
    cin.clear();

    // Ask the user to enter a date in the format MM/DD/YYYY
    cout << "INPUT\nEnter a date in the format MM/DD/YYYY: ";
    cin.getline(date, 11);

    //Clear the input buffer
    cin.clear();
}



// Prints the error message which will
//Then be followed by the reason why the date is invalid contained in the function checkDateFormat
void printError ();
void printError ()
{
    cout << "ERROR!\nPlease make sure that the date is in the format MM/DD/YYYY\n";
}


// This function will check if the date is in the correct format
int checkDateFormat(char* date);
int checkDateFormat(char* date)
{
    // Check if the input string has length 10
    if (strlen(date) > 10)
    {
        printError(); //Prints the error message
        cout << "It seems that there are more characters than needed\n"
            << "Check if you added an extra character\n";
        return 1;
    }

    else if (strlen(date) < 10)
    {
        printError(); //Prints the error message
        cout << "It seems that there are fewer characters than needed\n"
            << "Check if you are missing a character\n"
            << "Like missing the zero in front of the month or day\n";
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


void convertDayToWords(int day);
void convertDayToWords(int day)
{
    // Check if the input number is between 1 and 31
    if (day < 1 || day > 31)
    {
        cout << "Invalid day" << endl;
        return;
    }

    // Print the word form of the input day
    if (day >= 11 && day <= 19)
    {
        cout << elevenToNineteen[day - 11];
        return;
    }
    else if (day % 10 == 1)
    {
        cout << oneths[day];
        return;
    }
    else if (day % 10 == 2)
    {
        cout << tens[2] << "-" << oneths[day % 10];
        return;
    }
    else if (day % 10 == 3)
    {
        cout << tens[3] << "-" << oneths[day % 10];
        return;
    }
    else if (day % 10 >= 4 && day % 10 <= 9)
    {
        cout << tens[day / 10] << "-" << oneths[day % 10];
        return;
    }
    else
    {
        cout << tens[day / 10] << "-" << ones[day % 10] << "th";
        return;
    }
}



// This function prints a given number in words
// The number is assumed to be less than 9999
void convertNumToWords(int num);
void convertNumToWords(int num)
{
    // Check if the input number is between 0 and 9999
    if (num < 0 || num > 9999)
    {
        cout << "Number out of range" << endl;
        return;
    }

    // Convert the input integer to a string
    string numStr = to_string(num);

    // Add leading zeros if necessary to make the string length 4
    while (numStr.length() < 4)
    {
        numStr = "0" + numStr;
    }

    // Convert the input string to an array of strings, with each element representing a digit in the input integer
    string numArr[4];
    for (int i = 0; i < 4; i++)
    {
        numArr[i] = numStr[i];
    }

    // Print the word form of the input integer
    // checking if the number is zero
    if (num == 0)
    {
        cout << "zero" << endl;
        return;
    }

    // Print the thousands place like the 1 in 1000
    if (numArr[0] != "0")
    {
        cout << ones[stoi(numArr[0])] << " thousand ";
    }

    // Print the hundreds place like the 1 in 100
    if (numArr[1] != "0")
    {
        cout << ones[stoi(numArr[1])] << " hundred ";
    }

    // Print the tens place like 20, 30, 40, and so on
    if (numArr[2] != "0")
    {
        // If the current digit is a 1, print the corresponding teens word
        if (numArr[2] == "1")
        {
            cout << elevenToNineteen[stoi(numArr[3]) - 1] << endl;
            return;
        }

        // Print the tens word like 20, 30, 40, and so on
        else
        {
            cout << tens[stoi(numArr[2])] << " ";
        }
    }

    // Print ones place
    if (numArr[3] != "0")
    {
        // If the previous digit was a zero, print "and"
        if (numArr[2] == "0")
        {
            cout << "and ";
        }

        // Print the ones word
        cout << ones[stoi(numArr[3])];
    }
}




// This function splits the date into its parts
void printDateIntoWords(char* date);
void printDateIntoWords(char* date)
{
    // //print "Slit function entered"
    // cout << "\nSplit function entered" << endl;

    // Get the number of digits in the given number using the length of the string
    //then using strtok to get the month, day, and year
    //then using stoi to convert the month, day, and year to ints
    //I got the strtok function description from: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    int month = stoi(strtok(date, "/")); // Get the month
    int day = stoi(strtok(NULL, "/")); // Get the day
    int year = stoi(strtok(NULL, "/")); // Get the year

    // Print the original date
    cout << "\nOUTPUT\n" << month << "/" << day << "/" << year << " would be displayed as:"<< endl;

    // Print the date in words

    // print the month in words
    cout << months[month] << " ";

    // print the day in words
    // Use the convertNumToWords function to print the day integer into words
    convertDayToWords(day);

    // print the year in words
    cout << ", " ;
    convertNumToWords(year);
    
    cout << endl;
}



// !_____________________________MAIN FUNCTION_____________________________!
int main()
{
    // Declare variables
    char date[11]; // C-string to store the date
    int datecheck = 0; // Variable to store the result of the checkDate function    

    // Print the program welcome message
    cout << "Welcome to the Number to Words Converter!\n"
            << "This program converts a date in the format mm/dd/yyyy into words.\n"
            << "Where mm is the month, dd is the day, and yyyy is the year.\n";

    char choice = 'y'; // Variable to store the user's choice to continue or not
    
    do 
    {
        //A loop that asks the user for input and checks if the input is valid using the checkDate function
        //If the input is valid, the loop breaks
        //If the input is invalid, the loop continues
        //use a do while loop to ask the user for input

        datecheck = 1; // Reset the datecheck variable to 1
        
        while (datecheck == 1)
        {
            cout << " " << endl;    // Print a blank line
            cin.clear();   //clear the input buffer
            getDate (date); // Get the date from the user
            datecheck = checkDateFormat(date); // Check if the date is valid

            // Check if the input is valid
            if (datecheck == 0)
            {
                // If the input is valid, break the loop
                break;
            }
            else if (datecheck == 1)
            {
                // If the input is invalid, print an error message
                cout << "Please try again.";
            }
        }
        // cout << "\nHEYY If you can see this, that means the loop worked!!!" << endl;
        
        printDateIntoWords(date);   // Print the date in words using the printDateIntoWords function

        // Ask the user if they want to continue
        cout << "\nnWould you like to continue? (y/n): ";
        cin >> choice;        
        cin.clear();    //clear the input buffer

        // Check if the user entered a valid choice
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            // If the user entered an invalid choice, ask them to enter a valid choice
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (tolower(choice) == 'y');

    return 0;
}