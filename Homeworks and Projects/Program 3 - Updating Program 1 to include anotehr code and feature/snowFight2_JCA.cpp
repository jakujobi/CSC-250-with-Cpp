/*
Program 3 - Snowball Fight Team Score Checker with dynamically allocated arrays
    It allows the user to enter a team’s ID and displays the number of hits for that team
    Updates Program 1 to use dynamically allocated arrays
Created by: John Akujobi
Date: 11th of February 2023
Class: CSC 250 Fall 2023
*/




/*BUGS
The documentation for the bugs in this program are in your notion workspace

BUG1 - The program gave errors in the copyArray function
Solution    - I changed the function to take the address of the arrays as arguments and made several tweaks to it.
            - I also ran it through 2 online debuggers and found the errors
*/



#include <iostream>  // For cin, cout, endl
#include <fstream>  // For file input and output
#include <iomanip>  // For setw
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




//ReadFile(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);
void ReadFile(int& n, int*& id, int*& hits, int*& times)
{
    //open the file
    ifstream inFile;

    // open the file
    inFile.open("snowball_2.txt");

    // check if the file is opened successfully
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }

    // read the number of snowballs
    inFile >> n;

    // allocate memory for the arrays
    id = new int[n]; 
    hits = new int[n];
    times = new int[n];

    // read the data from the file and store it in the arrays
    for (int i = 0; i < n; i++)
    {
        inFile >> *(id + i) >> *(hits + i) >> *(times + i);
    }

    inFile.close();
}



// This function copies the contents of one array to another array
void copyArray(int* &thaPointer, int *arr, int n);
void copyArray(int* &thaPointer, int *arr, int n)
{
    // allocate memory for the array
    //thaPointer = new int[n];

    // copy the contents of the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = thaPointer[i];
    }
}
// Function call
//copyArrayV2(Id, ArrayTeamID, ArraySize);



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
    //ReadFile(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);
    int n;
    int *id, *attackHits, *timesHit;
    ReadFile(n, id, attackHits, timesHit);

    ArraySize = n;

    // Call the function to print the arrays
    for (int i = 0; i < n; i++)
    {
        // Print the snowball ID, number of hits, and number of times hit
        cout << "Snowball " << id[i] << ": " << attackHits[i] << " hits in " << timesHit[i] << " throws." << endl;
    }

    // Call the function to copy the arrays
    copyArray(id, ArrayTeamID, ArraySize);
    copyArray(attackHits, ArrayAttackHits, ArraySize);
    copyArray(timesHit, ArrayReceivedHits, ArraySize);


    delete [] id;
    delete [] attackHits;
    delete [] timesHit;

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