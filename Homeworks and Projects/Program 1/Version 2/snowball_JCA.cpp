/*
Program 1 - Snowball Fight Team Score Checker
    It allows the user to enter a team’s ID and displays the number of hits for that team
Created by: John Akujobi
Date: 22nd of January 2023
Class: CSC 250 Fall 2023
*/

/* Detailed program requirements by the professor (Paula Kurtenbach)
A text file named snowball.txt contains a 3-digit Team ID, number of times the team hit a member of another time (hits), and the number of times a member of this team was hit (times hit) for each team participating in a campus-wide snowball fight.  The data is organized on up to 50 lines in the data file, as shown below.

182 37 12
837 14 25
374 29 28
…

Write a program that allows the user to enter a team’s ID and displays the number of hits for that team.  You must use the binary search algorithm studied in Unit 1 in this program.  Your program should do the following:

1. Read the data from the file into partially filled, parallel arrays.
2. Sort the arrays, in parallel, putting the IDs in increasing order and keeping the number of hits and times hit in parallel with them. (When you swap two elements in the ID array, also swap the corresponding elements in the hits and times hit arrays.)
3. Enter a loop that does the following until the user chooses to quit:
    1. Read a team ID from the user
    2. Use the Binary Search algorithm to find the number of hits and times hit for that team.
    3. Print the number of hits, and times hit for the team requested. If the hits is greater than the times hit, print a Congratulations message.  If the ID entered is not in the data, print a “Not Found” message.

Your program must be modular, with separate functions to: read the data file, sort the arrays in parallel, input a number from the user, search, and print the results.  Your output should be well-organized, neat, and easy to read.
*/

/* Draft FLowchart Version 1.0
- Print the welcome message to the screen
- Open the file
- Fill the file contents into the 3 arrays; ArrayTeamID, ArrayAttackHits and ArrayReceivedHits
- Prints the menu
    - Option 1: Check team Score
    - Option 2: Quit the Program
- Receive user menu input, verify the input and call the necessary functions
- Read the team ID, and check if it is in the right format
- Search the list of array and find the team or print an error message
- Print the team ID, Attack hits, Received Hits
- Print Congratulations message if the Attack hits are more than the Received hits
- Repeat the loop
- After the user chooses the quit option, close the file
- End the program
*/

/*BUGS

BUG 0: The program does not read the file correctly and does not fill the arrays
Solution:
    Solution 0: 23rd of January 2023
    - I Tested it on the classmates computer and it worked. But on my computer it did not work.

    Solution 1: 25th of January 2023 during CSC 250 class
    - Informed the professor and she said it might be a problem with my the antivirus & security software on my computer.
    - Tried to put the folder wher the program is located in the exception list of the antivirus software but it did not work.
      - Did not try to disable the antivirus software because i borrowed the laptop from the school and i did not want to risk it.

    Solution 2: 25th of January 2023
    - I then tried reinstalling the compiler on computer (MSYS2 MinGW 64-bit) but it did not work.
    - Then i followed the instructions on the website to install the compiler to the PATH on the computer using the control panel.
    - I added the path to the bin folder of the compiler to the PATH and the program worked.


*/



#include <iostream>
#include <fstream>
using namespace std;

// Max size of the arrays
//Using 100 to be safe even though the file only has 50 lines
const int MAX_SIZE = 100;  

// Function to print welcome message
void Welcome()
{
    cout << "\nWelcome to The Snowball Fight Team Score Checker v1.0" << endl;
    cout << "This program is designed to help you check the scores of a team" << endl;
    cout << "And it tells you if they won or not." << endl;
    cout << "Lets get started" << endl;
    cout << endl;
}
//function call
//Welcome();



// Function to read the file and fill the arrays
void ReadFile(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int &ArraySize)
{
    ifstream file("snowball.txt");  // open the file

    // check if file is open
    if (!file.is_open())
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    int i = 0; // counter variable

    // Loop to read the file and fill the arrays ArrayTeamID, ArrayAttackHits and ArrayReceivedHits
    while (file >> ArrayTeamID[i] >> ArrayAttackHits[i] >> ArrayReceivedHits[i] && i < MAX_SIZE) 
    {
        i++;   // increment the counter with each iteration
    }
    ArraySize = i;  // store the size of the array

    file.close();   // close the file
}
//function call
//ReadFile(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);


// Function to sort the arrays in parallel
void SortArrays(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize)
{
    // Bubble sort algorithm
    for (int i = 0; i < ArraySize - 1; i++)
    {
        //Inner loop to compare the elements
        for (int j = i + 1; j < ArraySize; j++)
        {
            // Check if the element is greater than the next element
            if (ArrayTeamID[i] > ArrayTeamID[j])
            {
                // Swap the elements
                swap(ArrayTeamID[i], ArrayTeamID[j]);  
                swap(ArrayAttackHits[i], ArrayAttackHits[j]);
                swap(ArrayReceivedHits[i], ArrayReceivedHits[j]);
            }
        }
    }
}
//function call
//SortArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);



// Function to search for the team using binary search
int SearchTeam(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize, int teamID)
{
    // Initialize the variables, left index, right index and middle index
    int left = 0;   // left index
    int right = ArraySize - 1; // right index
    int middle; // middle index

    // Loop to search for the team
    while (left <= right)
    {
        middle = (left + right) / 2;

        // Check if the team is found
        if (ArrayTeamID[middle] == teamID)
        {
            return middle;
        }

        // Check if the team is in the right half
        else if (ArrayTeamID[middle] < teamID)
        {
            left = middle + 1;
        }

        // Check if the team is in the left half
        else
        {
            right = middle - 1;
        }
    }

    return -1;  // Return -1 if the team is not found which is then used to print the error message
}
//function call
//int index = SearchTeam(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize, teamID);



//1st version of Binary Search
// int SearchTeam(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize, int TeamID);
// int  SearchTeam(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize, int TeamID)
// {
//     int i = 0;
//     while (i < ArraySize)
//     {
//         if (ArrayTeamID[i] == TeamID)
//         {
//             cout << "Team ID: " << ArrayTeamID[i] << endl;
//             cout << "Attack Hits: " << ArrayAttackHits[i] << endl;
//             cout << "Received Hits: " << ArrayReceivedHits[i] << endl;
//             if (ArrayAttackHits[i] > ArrayReceivedHits[i])
//             {
//                 cout << "Congratulations! You won the snowball fight" << endl;
//             }
//             break;
//         }
//         i++;
//     }

//     if (i == ArraySize)
//     {
//         cout << "Team ID not found" << endl;
//     }

//     int TeamKey = i;
//     return TeamKey;;
// }


// Function to print the score of the team
void PrintScore(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int index)
{
    cout << "Team ID: " << ArrayTeamID[index] << endl;
    cout << "Attack Hits: " << ArrayAttackHits[index] << endl;
    cout << "Received Hits: " << ArrayReceivedHits[index] << endl;

    // Check if the team won
    if (ArrayAttackHits[index] > ArrayReceivedHits[index])
    {
    cout << "Congratulations! The team won." << endl;
    }

    // Check if the team tied
    else if (ArrayAttackHits[index] == ArrayReceivedHits[index])
    {
        cout << "It was a tie." << endl;
    }

    // Check if the team lost
    else
    {
    cout << "Uh oh, The team lost." << endl;
    }
}
//function call
//PrintScore(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, TeamKey);


//This function prints the menu
//void PrintMenu(); // Function prototype
void PrintMenu()
{
    cout << "Main Menu" << endl;
    cout << "1. Check Team Score" << endl;
    cout << "2. Print all Team Scores" << endl;
    cout << "3. Quit the Program" << endl;
}
//function call
//PrintMenu();



//This function reads the team ID and checks if it is in the right format
//int GetTeamID();
int GetTeamID()
{
    int TeamID;  //local variable to store the TeamID
    cout << "Enter the Team ID: ";
    cin >> TeamID;

    //add validation for TeamID
    //if the TeamID is not in the right format, the user is asked to enter a valid TeamID
    //The ID must be a 3 digit number, so that means it must be between 100 and 999
    if (TeamID < 100 || TeamID > 999)
    {
        cout << "\nInvalid Team ID: It must be between 100 and 999" << endl;
        cout << "Please enter a valid Team ID" << endl;

        GetTeamID();  //recursive call to the function making it repeat until the user enters a valid TeamID instead of using a while loop
    }

    return TeamID;
}
//function call
//TeamID = GetTeamID();


//This function prints the arrays in the right format: Team ID, Attack Hits, Received Hits
//void PrintArrays(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize);
void PrintArrays(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize)
{
    cout << "Team ID\t\tAttack Hits\tReceived Hits" << endl;
    for (int i = 0; i < ArraySize; i++)
    {
        cout << ArrayTeamID[i] << "\t\t" << ArrayAttackHits[i] << "\t\t" << ArrayReceivedHits[i] << endl;
    }
}
//function call
//PrintArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);




//!_______________________________________________________________________________________________________________________________
// Main function
int main()
{
    // Declare the arrays
    int ArrayTeamID[MAX_SIZE];   // Array to store the team ID
    int ArrayAttackHits[MAX_SIZE];  // Array to store the number of hits
    int ArrayReceivedHits[MAX_SIZE];    // Array to store the number of times hit

    // Declare the variables
    int ArraySize;  // Variable to store the size of the array
    int index;  // Variable to store the index of the team
    int choice; // Variable to store the choice of the user from the menu
    int teamID; // Variable to store the team ID

    // Call the function to print the welcome message
    Welcome();

    // Call the function to read the file
    ReadFile(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);

    //PrintArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize); // Test to print the arrays
    
    //Sort the arrays
    SortArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);

    // Loop to display the menu and get the user's choice
    do {
        // Call the function to print the menu
        PrintMenu();
        
        //Prompts and receives the user input
        cout << "Enter your choice: ";
        cin >> choice;

        //add validation for choice
        while (choice < 1 || choice > 3)
        {
            //if the choice is not in the right format, the user is asked to enter a valid choice
            cout << "\nInvalid choice: It must be 1, 2, or 3.\nPlease enter a valid choice: ";
            cin >> choice;
        }

        //Check if the user wants to check the score of a team
        if (choice == 1)
        {
            //Loop to get the team ID from the user if the team ID is not in the list
            do
            {
                teamID = GetTeamID(); // Get the team ID from the user

                // Call the function to search the team
                index = SearchTeam(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize, teamID);

                //if the team ID is not in the list, the user is asked to enter a valid team ID
                if (index == -1)
                {
                    cout << "\nThe team ID is not in the list. Please enter a valid team ID." << endl;
                }

            } while (index == -1);

            //// First version
            //teamID = GetTeamID(); // Get the team ID from the user
            //cout << "Enter team ID: ";
            //cin >> teamID;
            
            // // Call the function to search the team
            // index = SearchTeam(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize, teamID);

            //add empty line
            cout << endl;

            // Check if the team is found using the index returned by the function
            // If the index is not -1, the team is found
            // The index is then used to print the score of the team
            if (index != -1)
            {
                cout << endl;
                PrintScore(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, index);  // Print the score of the team
            }

            // // If the index is -1, the team is not found
            // else
            // {
            //     cout << "Oops, the Team not found." << endl;
            // }
        }

        else if (choice == 2)
        {
            SortArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);
            PrintArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);
        }

        //add empty line
        cout << endl;

    } while (choice != 3);

    return 0;
}