/* Schedule Program for Winter at the State Park
This program is used to record enrollment in the winter activities at a state park.

Created by: John Akujobi

Created on: 2nd February 2023
CSC 250 - Spring 2023
*/

/* Program Requirements by Prof Paula Kurtenbach

Schedule Program for Winter at the State Park
A local state park is having a “Winter Fun” event.
Interested people can sign up to compete in the following activities: 
skiing, curling, ice skating, and sledding, on 5 consecutive Saturdays.

Write a program that the park can use to record enrollment in the event.
Use a  2D array to hold the number of people participating in each activity, on each Saturday, where the activities are columns and the days are rows.

Provide a menu with the following options:
1. Enroll in an activity. (Ask the user for the activity and day)
2. Print the current enrollment. (Display entire array in a table with row and column headings, include the row totals, column totals, and overall total)
3. Exit

Your program must be modular, with separate functions for options 1 and 2 and also separate functions to find the row totals, column totals, and overall total.

*/

/* User Flowchart

- Welcome message
- Main menu displays
- Inputs the choice
- 1 - Enroll in an activity
    - Sees the list of day
    - Inputs the Day of activities
    
    - Sees the list of actvities
    - Inputs the Activity type
    - Print the last Enrollment for that day
    - Inputs the new enrollment
- 2 - Print the current enrollment
    - Sees the enrollment show on the screen
- 3 -  Exit
    - The program ends
- Repeats the menu

*/

/* List of functions

1. printWelcome
    - Prints the welcome message
    - void printWelcome()
    - printWelcome()
    
2. printMenu
    - prints the Mainmenu
    - void printMenu()
    - printMenu()
    
3. OP1_Enroll
    - Option to enroll in activity
    - void OP1_Enroll(int enrollment[][COLS])
    
4. printDay
    - Prints the day based on the input
    - void printDay( int Day)
    - printDay()
    
5. getDay
    - Prints the list of days, then gets, validates, and returns the chosen day from the user
    - int getDay()
    - getDay()
    
6. getActivity
    - Prints the acivity list, then gets, validates, and returns the activity type from the user
    - int getActivity()
    - getActivity()
    
7. calcRowTotals
    - Calculates the total for each row/day enrollment using an array and returns the total enrollment
    - void calcRowTotals(int enrollment[][COLS], int rowTotals[])
    - calcRowTotals(enrollment, rowTotals)
    
8. calcColTotals
    - Calculates the total for each column/activity enrollment using an array and returns the total enrollment
    - void calcColTotals(int enrollment[ROWS][], int colTotals[])
    - calcRowTotals(enrollment, colTotals)
    
9. printAverages
    - calculates and prints the average enrollments for each activity and the average daily enrollment
    - void printAverages
    - printAverages()
    
    ```
    AVERAGES
    ______________________
    Averages per sport
    Skiing🎿 = ##
    Curling🥌 = ##
    Ice Skating⛸️ = ##
    Sledding 🛷 =  ##
    
    Average daily = ##
    ```
    
10. printEnrollment
- Prints the enrollment current enrollment in the format below
- void printEnrollment
- printEnrollment

```
WINTER ACTIVITIES CURRENT ENROLLMENT
___________________________________________
DAYS     Sk🎿  Cu🥌   Ic⛸️   Sl🛷 | Total
Day1  |   20     40     20     40   | 120   -  Day1
Day2  |   30     60     30     60   | 180   -  Day2
Day3  |   40     20     40     20   | 120   -  Day3
Day4  |   60     30     60     30   | 180   -  Day4
Day5  |   20     40     20     40   | 120   -  Day5
____________________________________|______
Total    170    190    170    190   | 720

Total Enrolment = ####

AVERAGES
______________________
Averages per sport
Skiing🎿 = ##
Curling🥌 = ##
Ice Skating⛸️ = ##
Sledding 🛷 =  ##

Average daily = ##
```

*/



#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 5;
const int COLS = 4;

// TODO: BUG: I attempted to use string array but it was not working, so I used switch statement instead
// It kept showing me and error message saying "cannot convert 'const char*' to 'const string*' in initialization"
/*  const string ACTIVITIES[COLS] = {"Skiing🎿", "Curling🥌", "Ice Skating⛸️", "Sledding 🛷"};
    const string DAYS[ROWS] = {"Day 1", "Day 2", "Day 3", "Day 4", "Day 5"};
*/


//This function prints the day based on the input
void printDay(int day);
void printDay(int day)
{
    //using switch statement to print the day
    switch (day)
    {
        case 0:
            cout << "4th Feb 2023";
            break;

        case 1:
            cout << "11th Feb 2023";
            break;

        case 2:
            cout << "18th Feb 2023";
            break;

        case 3:
            cout << "25th Feb 2023";
            break;

        case 4:
            cout << "4th Mar 2023";
            break;

        default:
            cout << "ERROR: Invalid Day";
            break;
    }
}



//This function prints the activity based on the input
void printActivity(int activity);
void printActivity(int activity)
{
    //using switch statement to print the activity
    switch (activity)
    {
        case 0:
            cout << "Skiing🎿";
            break;

        case 1:
            cout << "Curling🥌";
            break;

        case 2:
            cout << "Ice Skating⛸️";
            break;

        case 3:
            cout << "Sledding 🛷";
            break;

        default:
            cout << "ERROR: Invalid Activity";
            break;
    }
}

//This function prints the heading of each activity based on the input
void printMiniActivity(int activity);
void printMiniActivity(int activity)
{
    //using switch statement to print the activity
    switch (activity)
    {
        case 0:
            cout << "Sk🎿";
            break;

        case 1:
            cout << "Cu🥌";
            break;

        case 2:
            cout << "Ic⛸️";
            break;

        case 3:
            cout << "Sl🛷";
            break;

        default:
            cout << "ERROR: Invalid Activity";
            break;
    }
}

//This function prints the very long line
void printLongLine();
void printLongLine()
{
    cout << "\n----------------------------------------------------" << endl;
}

//Function to print the welcome message
void printWelcome();
void printWelcome()
{
    printLongLine();
    cout << "\nWelcome to Winter Fun at the State Park\n"
         << "Here, you can enroll in skiing, curling, ice skating, and sledding on 5 consecutive Saturdays.\n\n";
}



//Function to print the main menu
void printMenu();
void printMenu()
{
    printLongLine();
    cout << "MAIN MENU\n"
         << "1. Enroll in an activity\n"
         << "2. Print the current enrollment\n"
         << "3. Exit\n";
}



//Function to get and validate the day choice
int getDay();
int getDay()
{
    int day;    //To hold the day choice
    
    /* //Initial list of days
    cout << "List of Days\n";
    cout << "1 - Day 1\n";
         << "2 - Day 2\n"
         << "3 - Day 3\n"
         << "4 - Day 4\n"
         << "5 - Day 5\n"
         << "Choose a day from the list (Number between 1 - 5): ";
    * I decided to instead use a loop to print the days
    */

    //using a loop to print the days
    cout << "\nLIST OF DAYS\n";
    for (int i = 0; i < ROWS; i++)
    {
        cout << i + 1 << " - ";
        printDay(i);
        cout << endl;
    }

    //Get the day choice
    cout << "Choose a day from the list \n--->: ";
    cin >> day; 

    //Validate the day choice
    while (day < 1 || day > 5)
    {
        cout << "INVALID DAY: Please choose a day between 1 and 5: \n-->: ";
        cin >> day;
    }

    //Tell the user the day they chose
    cout << "You chose: ";
    printDay(day - 1); //Print the day based on the input
    cout << endl;

    
    return day - 1; //Return the day choice but subtract 1 to match the array index
}



//Function to get and validate the activity choice
int getActivity();
int getActivity()
{
    int activity;

    /* //Initial list of activities
    //Print the list of activities
    cout << "List of Activities\n"
         << "1 - Sk🎿 - Skiing🎿\n"
         << "2 - Cu🥌 - Curling🥌\n"
         << "3 - Ic⛸️ - Ice Skating⛸️\n"
         << "4 - Sl🛷 - Sledding 🛷\n"
         << "Choose an activity from the list (Number between 1 - 4): ";
    * I decided to instead use a loop to print the activities
    */


    //Use a loop to print the activities
    cout << "\nLIST OF ACTIVITIES\n";
    for (int i = 0; i < COLS; i++)
    {
        cout << i + 1 << " - ";
        printActivity(i);
        cout << endl;
    }

    //Get the activity choice
    cout << "Choose an activity from the list \n-->: ";    
    cin >> activity;

    //Validate the activity choice
    while (activity < 1 || activity > COLS)
    {
        cout << "INVALID ACTIVITY: Please choose an activity between 1 and 4 \n-->: ";
        cin >> activity;
    }

    //Tell the user the activity they chose
    cout << "You chose: ";
    printActivity(activity - 1);  //Print the activity choice
    cout << endl;

    //Return the activity choice but subtract 1 to match the array index
    return activity - 1; 
}



//Function to enroll in an activity
void enrollInActivity(int enrollment[][COLS]);
void enrollInActivity(int enrollment[][COLS])
{
    //Get the day choice from the user
    int day = getDay();
    
    //Get the activity choice from the user
    int activity = getActivity();

    
    //Print the current enrollment
    cout << "\nThe last enrollment for ";
    printActivity (activity);
    cout << "  on day " << day + 1 << ", ";
    printDay(day);
    cout << " is -->: " << enrollment[day][activity] << endl;


    //Get the new enrollment from the user
    cout << "Enter the new enrollment\n-->: ";
    int newEnrollment;
    cin >> newEnrollment;
    
    //validate the new enrollment making sure it is not negative
    while (newEnrollment < 0)
    {
        cout << "INVALID ENROLLMENT: Please enter a positive number \n-->: ";
        cin >> newEnrollment;
    }

    //Update the enrollment
    enrollment[day][activity] = newEnrollment;
    
    //Print the success message
    cout << "\nYay! Enrollment updated successfully!\n";
}


//Function to calculate the row totals
void calcRowTotals(int enrollment[][COLS], int rowTotals[]);
void calcRowTotals(int enrollment[][COLS], int rowTotals[])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            rowTotals[i] += enrollment[i][j];
        }
    }
}



//Function to calculate the column totals
void calcColTotals(int enrollment[][COLS], int colTotals[]);
void calcColTotals(int enrollment[][COLS], int colTotals[])

{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++) 
        {
        colTotals[j] += enrollment[i][j];
        }
    }
}


void printEnrollment(int enrollment[][COLS], int rowTotals[], int colTotals[], int numActivities, int numDays);
void printEnrollment(int enrollment[][COLS], int rowTotals[], int colTotals[], int numActivities, int numDays)
{
    cout << endl;

    // print header
    printLongLine();
    cout << "CURRENT ACTIVITY ENROLLMENT";
    printLongLine();

    // print column headings which should print in the form below
    // DAYS     Sk🎿  Cu🥌   Ic⛸️   Sl🛷 | Total
    cout << "DAYS" << "    |" << setw(5);

    //print the column headers for the activities
    for (int i = 0; i < numActivities; i++)
    {
        cout << "   ";
        printMiniActivity(i);
    }
    cout << "  |  TOTAL";

    // print enrollment data
    for (int i = 0; i < numDays; i++)
    {
        cout << endl;
        //print the day at the beginning of the row
        cout << "Day " << i + 1 << "   |";

        //print the numbers for each activity
        for (int j = 0; j < numActivities; j++)
        {
            cout << setw(7) << enrollment[i][j];
        }
        cout << setw(5) << "    |    " << rowTotals[i] << setw(6) ;

        //print the day at the end of the row
        cout << setw(5) << "    -   ";
        printDay(i);

    }
    printLongLine();

    // print row totals

    // print column totals
    cout << "Total" << "   |";
    int TotalEnrollment = 0;
    for (int i = 0; i < numActivities; i++)
    {
        cout << setw(7) << colTotals[i];
        
        //add the column totals to get the total enrollment
        TotalEnrollment += colTotals[i];
    }
    cout << setw(5) << "    |    " << TotalEnrollment << setw(6) ;
    printLongLine();

    // print total enrollment
    cout << "\nTotal Enrollment = " << TotalEnrollment << endl;

    //print average daily enrollment
    float averageDailyEnrollment = (float)TotalEnrollment / (float)numDays;
    cout << "Average Daily Enrollment = " << averageDailyEnrollment << endl;

    printf("\n");
}


//Function to print the averages
void printAverages(int enrollment[][COLS], int rowTotals[], int colTotals[]);
void printAverages(int enrollment[][COLS], int rowTotals[], int colTotals[])
{
    int numberOfActivities = COLS;
    int numberOfStudents = ROWS;
    float average;

    cout << "ACTIVITY AVERAGES" << endl; //print the header

    //calculate the average for each activity
    for (int i = 0; i < numberOfActivities; i++)
    {
        average = (float)colTotals[i] / (float)numberOfStudents;

        printActivity(i);
        cout << " : " << average << endl;
    }

}




//Main function
int main()
{
    //Array storing the enrollment data
    int enrollment[ROWS][COLS] = {{0}};

    //Array to store the row and columns totals
    int rowTotals[ROWS] = {0};
    int colTotals[COLS] = {0};

    int choice; //To hold the user's choice

    //Call the function to print the welcome message
    printWelcome();

    //Loop to continue displaying the menu until the user chooses to exit
    do {
        // Call the function to print the menu
        printMenu();
        
        //Prompts and receives the user input
        cout << "Enter your choice \n--> ";
        cin >> choice;

        //add validation for choice
        while (choice < 1 || choice > 3)
        {
            //if the choice is not in the right format, the user is asked to enter a valid choice
            cout << "\nINVALID CHOICE: Please enter 1, 2, or 3.\nTry again";

            // Call the function to print the menu
            printMenu();
            
            //Prompts and receives the user input
            cout << "Enter your choice \n--> ";
            cin >> choice;
        }

        //Check if the user wants to check the score of a team
        if (choice == 1)
        {
            enrollInActivity(enrollment);
        }

        else if (choice == 2)
        {
            //Calculate the row and column totals
            calcRowTotals(enrollment, rowTotals);
            calcColTotals(enrollment, colTotals);

            //Print the enrollment data
            printEnrollment(enrollment, rowTotals, colTotals, COLS, ROWS);

            //Print the averages
            printAverages(enrollment, rowTotals, colTotals);
        }

        else if (choice == 3)
        {
            cout << "\nEXITING: Thank you for using the program.\nGoodbye!\n\n";
            exit(0);
        }

        //add empty line
        cout << endl;

    } while (choice != 3);

    return 0;
}

