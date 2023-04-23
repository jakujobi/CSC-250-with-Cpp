#include <iostream>
#include "Scooter.h"
using namespace std;
// Member Methods

//Constants
const int ACCEL = 2; // Acceleration in mph
const int DECEL = 3; // Deceleration in mph
//const int HIGHEST_MAX = 100; // Maximum speed in mph

// Default Constructor
Scooter::Scooter() {
	type = "";	// set to empty string using null
	max_speed = 0;	// set to 0
	current_speed = 0;	// set to 0
	//int test = 1 + HIGHEST_MAX;
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
		cout << "\rCurrent speed: " << current_speed << " km/h" << flush;
		//this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds pause
		// the while loop is used to keep the displaySpeed function running
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
