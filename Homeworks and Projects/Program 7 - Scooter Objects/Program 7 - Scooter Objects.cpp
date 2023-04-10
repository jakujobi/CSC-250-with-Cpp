// Program 7 - Scooter Objects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Program Requirements
* Write a Scooter class that has the following **private** member variables:

| Variable Name | Description |
| --- | --- |
| type | A string that holds the brand and model of the scooter. |
| max_speed | A float that holds the maximum speed for the scooter. |
| current_speed | A float that holds the current charge as a percentage. |

In addition, the class should have the following constructors and member functions:

- **Default Constructor:** The constructor should create an empty Scooter object, set the name to the empty string, and max and current speed to 0.
- **2nd Constructor:** The second constructor should accept the scooter’s name and max speed as arguments. It should create an object with the requested name and max speed, setting the current speed to 0.
- **Accessors:** Appropriate accessor functions to return the values stored in an object’s member variables.
- **Mutators:** Appropriate mutator functions to set the values stored in an object’s member variables. Validate the data as is appropriate for the field
- **`speedUp()`**: Increase speed by 2 mph, up to max_speed.
- **`slowDown()`**: Decrease speed by 3 mph, down to 0.

Demonstrate the class in a **program (main)** that creates a scooter object,
    uses a loop to increase the speed in increments of 2 mph until reaching the max speed, printing the current speed after each increment.
Then use a second loop to decrease the speed by decrements of 3 mph down to 0, printing speed after each increment.

*/


//Learnings
/*
	- learned to use \r to return to the beginning of the line
		- https://www.codespeedy.com/use-of-r-in-cpp-carriage-return-to-escape-special-characters/

*/

//Struggles
/*
*/

//Libraries
#include <iostream> // cout, cin, endl
#include <string>   // string class
#include <iomanip>  // setw, setfill
#include <fstream>  // ifstream, ofstream, fstream
#include <cstring>  // strcpy
#include <thread>   // this_thread::sleep_for in the loadingAnimation function
#include <chrono>   // chrono::steady_clock
//#include <conio.h> // for reading the arrow keys
using namespace std;


//Constants
const int ACCEL = 2; // Acceleration in mph
const int DECEL = 3; // Deceleration in mph
const int HIGHEST_MAX = 100; // Maximum speed in mph

//Class Definition for Scooter
class Scooter
{
	private:
		string type;	// brand and model
		float max_speed; // maximum speed in mph
		float current_speed; // current speed in mph

	public:
		// Default Constructor
		Scooter();
		//Scooter() : type(""), max_speed(0.0), current_speed(0.0), time_driven(0.0) {}
			//Learned this from StackOverflow showing how to put a function on a single line

		// 2nd Constructor that accepts the scooter’s name and max speed as arguments.
		Scooter(string userTypeAndModel, float userMaxSpeed);

		// Accessors
		string getType(); //returns the type and model of scooter as a string
		float getMaxSpeed(); // returns the max speed of the scooter as a float
		float getCurrentSpeed(); // returns the current speed of the scooter as a float

		// Mutators
		void setType(string userTypeAndModel); //sets the type and model of the scooter
		void setMaxSpeed(float userMaxSpeed); //sets the max speed of the scooter
		void setCurrentSpeed(float userCurrentSpeed); //sets the current speed of the scooter
		void speedUp(); // increases the speed of the scooter by the acceleration constant if the current speed is less than the max speed
		void slowDown(); // decreases the speed of the scooter by the deceleration constant if the current speed is greater than 0
		void displaySpeed(); // displays the current speed of the scooter like a digital speedometer
		void hardStop(); // sets the current speed to 0
		//void honkHorn(); // honks a horn
		void controlSpeed(Scooter& scooter); // controls the speed of the scooter using the arrow keys
};

// Member Methods

// Default Constructor
Scooter::Scooter() {
	type = "";	// set to empty string using null
	max_speed = 0;	// set to 0
	current_speed = 0;	// set to 0
}

// 2nd Constructor that accepts the scooter’s name and max speed as arguments.
Scooter::Scooter(string userTypeAndModel, float userMaxSpeed) {
	type = userTypeAndModel;
	max_speed = userMaxSpeed;
	current_speed = 0;
}

// Accessors
string Scooter::getType() {	//returns the type and model of scooter as a string
	return type;
}

float Scooter::getMaxSpeed() { // returns the max speed of the scooter as a float
	return max_speed;
}

float Scooter::getCurrentSpeed() { // returns the current speed of the scooter as a float
	return current_speed;
}

// Mutators
void Scooter::setType(string userTypeAndModel) {	//sets the type and model of the scooter
	type = userTypeAndModel;
}

void Scooter::setMaxSpeed(float userMaxSpeed) { //sets the max speed of the scooter
	max_speed = userMaxSpeed;
}

void Scooter::setCurrentSpeed(float userCurrentSpeed) { //sets the current speed of the scooter
	current_speed = userCurrentSpeed;
}

void Scooter::speedUp() { // increases the speed of the scooter by the acceleration constant if the current speed is less than the max speed
	if (current_speed < max_speed) {
		current_speed += ACCEL;
	}
	else {
		cout << "You are already at max speed!" << endl;
	}
}

void Scooter::slowDown() { // decreases the speed of the scooter by the deceleration constant if the current speed is greater than 0
	if (current_speed > 0) { // prevents the current speed from going below 0
		current_speed -= DECEL;
	}
	else { // tells the user that they are already stopped if the current speed is 0
		cout << "You are already stopped!" << endl;
	}
}

void Scooter::displaySpeed() { // displays the current speed of the scooter like a digital speedometer
	while (true) {
		cout << "\rCurrent speed: " << current_speed << " km/h" << flush;
		this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds pause
	} // the while loop is used to keep the displaySpeed function running
		// the \r is used to return to the beginning of the line
		// the flush is used to flush the buffer
		// Then it pauses for 500 milliseconds and uses the thread and chrono libraries
}

void Scooter::hardStop() {
	current_speed = 0;
}

// void Scooter::controlSpeed(Scooter& scooter) {
//     while (true) {
//         char ch = getch();
//         if (ch == 72) { // up arrow
//             scooter.speedUp();
//         } else if (ch == 80) { // down arrow
//             scooter.slowDown();
//         }
//     }
// }


// Other Functions
void Line(int num);	// draws a line of dots
void loadingAnimation(int seconds); // displays a loading animation
void configureScooter (Scooter *scooter); // prompts the user for brand and model
void getControls(Scooter *scooter); // prompts the user for max speed
void displaySpeed(Scooter *scooter); // displays the scooter's speed as a digital speedometer

//!______________________________________________________________
int main()
{
	system("cls");	// clears the screen
					// learned from StackOverflow
	loadingAnimation(3);	// displays a loading animation

	Scooter scooter; // creates a scooter object with the default constructor

	configureScooter(&scooter); // set up the scooter properties from the user
	scooter.displaySpeed(); // display the current speed of the scooter
	getControls(&scooter);	// get controls from the user
	scooter.displaySpeed(); // display the current speed of the scooter

	return 0;
}



//!Functions_________________________________________________________________________________________________

// Prints a line of dashes
void Line(int num) {
	for (int i = 0; i < num; i++) {
		cout << "-";
	}
	cout << endl;
	//cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
}

void loadingAnimation(int seconds) {	// displays a loading animation
	string dots;    //to store the printed stuff
	cout << "Loading...";
	dots = "Beep! ";//🛴
	//to make the loading animation
	for (int i = 0; i < seconds; i++) {
		this_thread::sleep_for(chrono::seconds(1));
		cout << dots << flush << "\a";
	}
	cout << endl;
}

// Prompts the user for brand and model and sets them to the object's properties
void configureScooter (Scooter *scooter){
	string userType;	//type and model
	float userMaxSpeed;	//max speed in mph

	do{
		//ask user for name and model
		cout << "Enter the type and model of the scooter: ";
		getline(cin, userType);
		cin.clear();
		cin.ignore();

		//verify length of name and model
		if (userType.length() < 2) {
			cout << "OOPS! Name and model cannot be that empty!" << endl;
		}
	} while (userType.length() < 1); //repeat until the user enters a valid name and model
	cout << "Name and model: " << userType << endl;

	do {
		//ask user for max speed
		cout << "Enter the maximum speed of the scooter: ";
		cin >> userMaxSpeed;
		cin.ignore();
		cin.clear();
		//verify max speed
		if (userMaxSpeed < 0) {
			cout << "OOPS! Maximum speed cannot be negative!" << endl;
		}
		else if (userMaxSpeed > HIGHEST_MAX) {
			cout << "WHOA!! These scooters can't go as fast as "
			<< HIGHEST_MAX
			<< "MPH"
			<<"\nSorry the max speed has gotta be lower for safety reasons."<< endl;
		}
	} while (userMaxSpeed < 0); //repeat until the user enters a valid max speed
	cout << "Maximum speed: " << setw(4) << userMaxSpeed << endl;

	//Assign the values to the object
	scooter->setType(userType);
	scooter->setMaxSpeed(userMaxSpeed);
}


int getControls(Scooter *scooter) {	// prompts the user for brand and model
	int choice; // user choice
	do {
			//Print the main menu
			Line(50);
			cout << "SCOOTER CONTROLLER" << endl;
			do {
				cout
					<< "1. Speed Up\n"
					<< "2. Slow Down\n"
					<< "3. Hard Stop\n"
					<< "4. Honk Horn\n"
					<< "5. Exit\n"
					<< endl;
				
				//Get the user's choice
				cout << "Enter your choice (1-5): ";
				cin >> choice;
				cin.ignore();
				cin.clear();

				//Validate the user's choice
				if (choice < 1 || choice > 5) {
					cout << "OOPS! Invalid choice. Please enter number from 1 to 5" << endl;
				}
			} while (choice < 1 || choice > 5); //repeat until the user enters a valid choice

			switch (choice) { // Call the appropriate function based on user input
			case 1:
					scooter->speedUp();
					break;
			case 2:
					scooter->slowDown();
					break;
			case 3:
					scooter->hardStop();
					break;
			case 4:
					//scooter->honkHorn();
					break;
			case 5:
					cout << "/nGoodBye" << endl;
					loadingAnimation(3);
					exit(0);
			default:
				cout << "OOPS! Invalid choice. Please enter number from 1 to 6" << endl;
				break;
			}
		} while (choice != 5);

		//system("pause"); //pause the program
		return choice;
}

void displaySpeed (Scooter *scooter){ // displays the current speed of the scooter like a digital speedometer
	while (true) {
		cout << "\rCurrent speed: " << scooter->getCurrentSpeed() << " km/h" << flush;
		this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds pause
	} // the while loop is used to keep the displaySpeed function running
		// the \r is used to return to the beginning of the line
		// the flush is used to flush the buffer
		// Then it pauses for 500 milliseconds and uses the thread and chrono libraries
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
