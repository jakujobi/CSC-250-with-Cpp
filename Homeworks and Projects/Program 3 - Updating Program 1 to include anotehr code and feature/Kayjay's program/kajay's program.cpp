//Kajay Gordon
//Ms. Paula Kurtenbach
//CSC 250
// This program allows the user to enter a team's ID and
//  display the number of hits for that team
//


// libraries
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
 
//constants
const int SIZE= 50; // array size
const int SENTINEL = -99;

// function prototypes for input, output, and processing
int readData(int * & idArray, int * & hits, int * & times_hit);
void sortArray (int * & idArray, int * & hits, int * & times_hit);
int readUserID();
int binarySearch(const int idArray[], int count, int userID);
void printResults( const int idArray[], int hits[], int times_hit[], int item_position);
 

int main()
{
    
    int item_position;  // position of the item in the array
    int  * idArray;    // array of ids
    int  * hits;    // array of hits
    int  * times_hit;   // array of times hit
    int user;    // user id
    int count = 50; // array size
 
    // allocate hits and times hit array, read the data from the file
    //   return the array size
    item_position = readData( idArray, hits,times_hit);
    
    // sort the arrays
    sortArray( idArray, hits, times_hit);
   
    // read the ids from the user
    user = readUserID();
    
    // use sentinel-controlled loop to process ids
    while (user != SENTINEL)
    {
        // search for the id in the array and return the position to item_position
        item_position = binarySearch(idArray,count, user);

        // print the results
        printResults(idArray, hits, times_hit, item_position);

        // read the next id from the user
        user = readUserID();
    }
    

    //item_position  = binarySearch(idArray, count, user);
    
    // print the results
    //printResults(idArray, hits, times_hit, item_position);
    
    // delete the arrays
    delete [] idArray;
    delete [] hits;
    delete [] times_hit;

    idArray = hits = times_hit = nullptr; // set the pointers to null
    
 
    return 0;
}


// this function is used to read the data from the file
int readData(int * & idArray, int * & hits, int * & times_hit)
{
    // declare variables
    int item_position;
    
    // declare the input file stream
    ifstream infile;

    // open the input file
    infile.open("/Users/kajgordon/Documents/CSC250/Programming Assignment #3/SnowBall.txt");

    // check that the input file is opened
    if(!infile)
    {
        cout << "Error opening File.txt\n"; // display error message
        exit(102);  // exit the program
    }
    
    // read the array size from the file
    infile >> item_position;
    
    // dynamically allocate the id, hits, and times hit arrays
    idArray = new int [item_position];
    hits = new int [item_position];
    times_hit = new int [item_position];
    
    // read the data from the file into the id, hits and times hit array
    cout << "Reading the id, hits,and times hit for " <<  item_position
    << " teams from snowball.txt.\n\n";
    
    // read the data from the file into the id, hits and times hit array
    for (int i =0; i < item_position; i++)
    {
        infile >> idArray[i] >> hits[i] >> times_hit[i];
    }
    
    // close the input file
    infile.close();

    // return the array size
    return item_position;
}
 

void sortArray (int * & idArray, int * & hits, int * & times_hit)
{
    // declare variables
    int swapped;

    do
    {
        // swap the elements
        swapped = false;

        // check the elements
        for(int i = 0; i < (SIZE - 1); i++)
        {
            // check if the current element is smaller than the next element
            if(idArray[i] > idArray[i+1])
            {
                // swap the elements
                swap(idArray[i], idArray[i+1]);
                swap(hits[i], hits[i+1]);
                swap(times_hit[i], times_hit[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
}


// this function is used to read the ids from the user
int readUserID()
{
    // declare variables
    int userID;

    // read the id from the user
    cout << "Enter the team's ID number or -99 to quit:  ";

    cin >> userID;
 
    return userID;
}


// this function is used to read the times from the user
int binarySearch(const int idArray[], int count, int userID)
 
{
    // declare variables
    int middle_loc;
    int first, last;
    int position = -1;
    
    first = 0;
    last = count-1;

// search the array
while(position == -1 && first <= last)
{
    middle_loc = (first+last) / 2;
    if(userID > idArray[middle_loc])
    {
        first = middle_loc + 1;
    }

    else if(userID < idArray[middle_loc])
    {
        last = middle_loc - 1;
    } 

    else
    {
        position = middle_loc;
    }
 }
    
    return position;
}

 // print all the info
void printResults( const int idArray[], int hits[], int times_hit[], int item_position)
 
{
 
    // Print the results
    cout << "\n" << "Hits: " << hits[item_position] << "     Times Hit: " << times_hit[item_position] <<"\n" <<  endl;
    
    // check if the user won
    if(hits[item_position] > times_hit[item_position])
        cout << "Congrats! You won!\n" << endl;
    
    // check if the user has the same scores for hits and times_hit
    else if(hits[item_position] == times_hit[item_position])
        cout << "Its a tie!\n" << endl;
    
    // check if the user lost
    else
        cout << "Better luck on the next game!\n" << endl;
 
}
