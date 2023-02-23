#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void getInput(char* date);
void convertToWords(char* date);
void outputResult(char* result);

char* months[] = {"", "January", "February", "March", "April", "May",
                  "June", "July", "August", "September", "October", "November", "December"};

char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char* elevenToNineteen[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main()
{
    char date[11];

    // Get user input
    getInput(date);

    // Convert date to words
    convertToWords(date);

    return 0;
}

void getInput(char* date)
{
    cout << "Enter a date in the format MM/DD/YYYY: ";
    cin.getline(date, 11);
}

void convertToWords(char* date)
{
    int month = stoi(strtok(date, "/"));
    int day = stoi(strtok(NULL, "/"));
    int year = stoi(strtok(NULL, "/"));

    if (month < 1 || month > 12)
    {
        cout << "Invalid month" << endl;
        return;
    }
    if (day < 1 || day > 31)
    {
        cout << "Invalid day" << endl;
        return;
    }
    if (year < 0 || year > 9999)
    {
        cout << "Invalid year" << endl;
        return;
    }

    cout << months[month] << " " << ones[day] << " ";

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

    cout << ", ";

    if (year >= 1000)
    {
        cout << ones[year / 1000] << " thousand ";
        year %= 1000;
    }
    if (year >= 100)
    {
        cout << ones[year / 100] << " hundred ";
        year %= 100;
    }
    if (year >= 20)
    {
        cout << tens[year / 10] << " ";
        year %= 10;
    }
    if (year >= 11 && year <= 19)
    {
        cout << elevenToNineteen[year - 11];
    }
    else if (year >= 1 && year <= 9)
    {
        cout << ones[year];
    }
    else if (year == 10)
    {
        cout << "ten";
    }

    cout << endl;
}

void outputResult(char* result)
{
    cout << result << endl;
}
