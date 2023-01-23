#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 50;

// Function to print welcome message
void PrintWelcomeMessage() {
    cout << "Welcome to The Snowball Fight Team Score Checker v1.0" << endl;
    cout << "This program is designed to help you check the scores of a team" << endl;
    cout << "And it tells you if they won or not." << endl;
    cout << "Lets get started" << endl;
    cout << endl;
}

// Function to read the file and fill the arrays
void ReadFile(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int &ArraySize) {
    ifstream file("snowball.txt");

    // check if file is open
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    int i = 0;
    while (file >> ArrayTeamID[i] >> ArrayAttackHits[i] >> ArrayReceivedHits[i] && i < MAX_SIZE) {
        i++;
    }
    ArraySize = i;
    file.close();
}

// Function to sort the arrays in parallel
void SortArrays(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize)
{
    for (int i = 0; i < ArraySize - 1; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            if (ArrayTeamID[i] > ArrayTeamID[j])
            {
                swap(ArrayTeamID[i], ArrayTeamID[j]);
                swap(ArrayAttackHits[i], ArrayAttackHits[j]);
                swap(ArrayReceivedHits[i], ArrayReceivedHits[j]);
            }
        }
    }
}

// Function to search for the team using binary search
int BinarySearch(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int ArraySize, int teamID)
{int left = 0, right = ArraySize - 1, middle;
while (left <= right) {
middle = (left + right) / 2;
if (ArrayTeamID[middle] == teamID) {
return middle;
}
else if (ArrayTeamID[middle] < teamID) {
left = middle + 1;
}
else {
right = middle - 1;
}
}
return -1;
}

// Function to print the score of the team
void PrintScore(int ArrayTeamID[], int ArrayAttackHits[], int ArrayReceivedHits[], int index) {
cout << "Team ID: " << ArrayTeamID[index] << endl;
cout << "Attack Hits: " << ArrayAttackHits[index] << endl;
cout << "Received Hits: " << ArrayReceivedHits[index] << endl;
if (ArrayAttackHits[index] > ArrayReceivedHits[index]) {
cout << "Congratulations! The team won." << endl;
}
}

int main() {
PrintWelcomeMessage();
int ArrayTeamID[MAX_SIZE];
int ArrayAttackHits[MAX_SIZE];
int ArrayReceivedHits[MAX_SIZE];
int ArraySize;

ReadFile(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);
SortArrays(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize);

int choice;
do {
    cout << "1. Check team score" << endl;
    cout << "2. Quit program" << endl;
    cin >> choice;

    if (choice == 1) {
        int teamID;
        cout << "Enter team ID: ";
        cin >> teamID;
        int index = BinarySearch(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, ArraySize, teamID);
        if (index != -1) {
            PrintScore(ArrayTeamID, ArrayAttackHits, ArrayReceivedHits, index);
        }
        else {
            cout << "Team not found." << endl;
        }
    }
} while (choice != 2);

return 0;
}

