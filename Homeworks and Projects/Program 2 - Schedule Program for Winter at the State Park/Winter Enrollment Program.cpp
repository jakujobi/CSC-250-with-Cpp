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
const string ACTIVITIES[COLS] = {"Skiing🎿", "Curling🥌", "Ice Skating⛸️", "Sledding 🛷"};

//Function to print the welcome message
void printWelcome() {
    cout << "Welcome to Winter Fun at the State Park\n"
         << "Here, you can enroll in skiing, curling, ice skating, and sledding on 5 consecutive Saturdays.\n\n";
}

//Function to print the main menu
void printMenu() {
    cout << "Main Menu\n"
         << "1. Enroll in an activity\n"
         << "2. Print the current enrollment\n"
         << "3. Exit\n\n"
         << "Enter your choice (1-3): ";
}

//Function to get and validate the day choice
int getDay() {
    int day;
    cout << "List of Days\n"
         << "1 - Day 1\n"
         << "2 - Day 2\n"
         << "3 - Day 3\n"
         << "4 - Day 4\n"
         << "5 - Day 5\n"
         << "Choose a day from the list (Number between 1 - 5): ";
    cin >> day;
    while (day < 1 || day > 5) {
        cout << "Invalid day. Please choose a number between 1 and 5: ";
        cin >> day;
    }
    return day - 1;
}

//Function to get and validate the activity choice
int getActivity() {
    int activity;
    cout << "List of Activities\n"
         << "1 - Sk🎿 - Skiing🎿\n"
         << "2 - Cu🥌 - Curling🥌\n"
         << "3 - Ic⛸️ - Ice Skating⛸️\n"
         << "4 - Sl🛷 - Sledding 🛷\n"
         << "Choose an activity from the list (Number between 1 - 4): ";
    cin >> activity;
    while (activity < 1 || activity > 4) {
        cout << "Invalid activity. Please choose a number between 1 and 4: ";
        cin >> activity;
    }
    return activity - 1;
}

//Function to enroll in an activity
void enrollInActivity(int enrollment[][COLS]) {
    int day = getDay();
    int activity = getActivity();
    cout << "The last enrollment for " << ACTIVITIES[activity] << " on day " << day + 1 << " is " << enrollment[day][activity] << endl;
    cout << "Enter the new enrollment: ";
    int newEnrollment;
    cin >> newEnrollment;
    enrollment[day][activity] = newEnrollment;
    cout << "Enrollment updated successfully!\n\n";
}

//Function to calculate the row totals
void calcRowTotals(int enrollment[][COLS], int rowTotals[]) {
    for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
rowTotals[i] += enrollment[i][j];
}
}
}

//Function to calculate the column totals
void calcColTotals(int enrollment[][COLS], int colTotals[]) {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
colTotals[j] += enrollment[i][j];
}
}
}

//Main function
int main() {
int enrollment[ROWS][COLS] = {{0}};
int rowTotals[ROWS] = {0};
int colTotals[COLS] = {0};
getEnrollment(enrollment);
calcRowTotals(enrollment, rowTotals);
calcColTotals(enrollment, colTotals);

cout << "Row Totals: ";
for (int i = 0; i < ROWS; i++) {
    cout << rowTotals[i] << " ";
}
cout << endl;

cout << "Column Totals: ";
for (int i = 0; i < COLS; i++) {
    cout << colTotals[i] << " ";
}
cout << endl;

return 0;
}

