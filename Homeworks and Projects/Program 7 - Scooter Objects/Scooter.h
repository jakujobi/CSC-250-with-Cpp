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