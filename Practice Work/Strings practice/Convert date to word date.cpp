// write a program that converts the date from numeric form to word form
// for example 10/29/2014 will be converted to January Twenty Nine, Two Thousand and Fourteen


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int month, day, year;
    string monthName;
    cout << "Enter the month, day, and year in numeric form: ";
    cin >> month >> day >> year;

    switch (month)
    {
    case 1: monthName = "January";
        break;
    case 2: monthName = "February";
        break;
    case 3: monthName = "March";
        break;
    case 4: monthName = "April";
        break;
    case 5: monthName = "May";
        break;
    case 6: monthName = "June";
        break;
    case 7: monthName = "July";
        break;
    case 8: monthName = "August";
        break;
    case 9: monthName = "September";
        break;
    case 10: monthName = "October";
        break;
    case 11: monthName = "November";
        break;
    case 12: monthName = "December";
        break;
    }
    cout << monthName << " " << day << ", " << year << endl;
    return 0;
}


//function to convert string to int
int stringToInt(string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

//function to convert int to string
string intToString(int n)
{
    string result = "";
    while (n > 0)
    {
        result = char(n % 10 + '0') + result;
        n /= 10;
    }
    return result;
}



//function to convert date to word date
string dateToWordDate(string date)
{
    string monthName;

    //pick the month
    string month = date.substr(0, 2);

    //pick the day
    string day = date.substr(3, 2);

    //pick the year
    string year = date.substr(6, 4);


    int monthInt = stringToInt(month);
    int dayInt = stringToInt(day);
    int yearInt = stringToInt(year);

    switch (monthInt)
    {
    case 1: monthName = "January";
        break;
    case 2: monthName = "February";
        break;
    case 3: monthName = "March";
        break;
    case 4: monthName = "April";
        break;
    case 5: monthName = "May";
        break;
    case 6: monthName = "June";
        break;
    case 7: monthName = "July";
        break;
    case 8: monthName = "August";
        break;
    case 9: monthName = "September";
        break;
    case 10: monthName = "October";
        break;
    case 11: monthName = "November";
        break;
    case 12: monthName = "December";
        break;
    }
    return monthName + " " + day + ", " + year;
}

//function to print the month name using switch statements
void printMonth(int month)
{
    switch (month)
    {
        case 1: cout << "January";
            break;
        case 2: cout << "February";
            break;
        case 3: cout << "March";
            break;
        case 4: cout << "April";
            break;
        case 5: cout << "May";
            break;
        case 6: cout << "June";
            break;
        case 7: cout << "July";
            break;
        case 8: cout << "August";
            break;
        case 9: cout << "September";
            break;
        case 10: cout << "October";
            break;
        case 11: cout << "November";
            break;
        case 12: cout << "December";
            break;
    }
}

//function to print the day name using switch statements
void printDay(int day)
{
    switch(day)
    {
        case
    }
}



//function to calculate the length of a string
int length(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        count++;
    }
    return count;
}


/* Function to calculate the length of a string using while loop

The function takes a string as input and uses a while loop to iterate over each character of the string.
For each character, the function increments the count variable by 1.
Once the while loop has iterated over all characters of the string, the function returns the final count value, which is the length of the string.
Essentially, the function counts the number of characters in the input string by iterating over the string and keeping a count of the number of iterations.
*/
int lengthWhile(string s)
{
    int count = 0;
    int i = 0;
    while (i < s.length())
    {
        count++;
        i++;
    }
    return count;
}


//function to calculate the length of a string using recursion
/*Explain how this works:
1. If the string is empty, return 0
2. If the string is not empty, return 1 + the length of the string without the first character
*/
int lengthRecursion(string s)
{
    if (s == "")
    {
        return 0;
    }
    else
    {
        return 1 + lengthRecursion(s.substr(1));
    }
}