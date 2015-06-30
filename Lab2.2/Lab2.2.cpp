/**
 * @author Jean-Luc Desroches
 * @date 05/04/2015
 * This program calculates the circumference of a circle, given a radius
 */
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/**
 * Class handles calculating the  and area of a circle, based on a user's input
 * @class CircleCalculator
 */
class CircleCalculator{
private:

	/**
	 * Prints the application header to the console
	 * @method print_header
	 */
	static void print_header(){
		cout << "/******************************************************************/" << endl;
		cout << "/****************** Beginning Circle Calculator *******************/" << endl;
		cout << "/******************************************************************/" << endl;
		cout << "/******************************************************************/" << endl;
	}

	/**
	 * Prints exit message to user
	 * @method print_exit
	 */
	static void print_exit(){
		cout << "/******************************************************************/" << endl;
		cout << "/*************** Thank you for using the calculator ***************/" << endl;
		cout << "/******************************************************************/" << endl;
		cout << "/******************************************************************/" << endl;
	}

	/**
	 * Gets the user to input the value of the circle's radius, will continue to ask until the input is valid
	 * @method get_radius
	 * @return {float} Radius entered by user
	 */
	static float get_radius(){
		bool isValid = false;
		float input;

		// get users input on circle's radius, if is not a valid input, ask again
		while(!isValid){
			cout << "What is the radius of the circle? ";
			if(cin >> input){
				isValid = true;
			}else{
				cout << "That was an invalid input, please enter a numeric value" << endl;
			}
		}

		return input;
	}


	/**
	 * Gets user input for the program
	 * @method get_input
	 * @return {bool} Boolean for whether user wishes to continue the application
	 */
	static bool get_input(){
		string input;

		// get users input for radius
		float radius = get_radius();
		cout << "The circumference of the circle is: " << calculate_circumference(radius) << endl;
		cout << "The area of the circle is: " << calculate_area(radius) << endl;

		// check whether user wishes to run the app again
		while(true){
			cout << "Would you like to run another calculation?(y/n) ";
			cin >> input;

			// convert string input to lowercase
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			if(input == "y" || input == "yes"){
				return false; // user wishes to enter another radius
			}else if(input == "n" || input == "no"){
				return true; // user has chosen to exit the app
			}else{
				cout << "please enter 'y' or 'yes' to enter another radius, or to exit, type 'n' or 'no'" << endl;
			}
		}
	}

	/**
	 * Calculates the area of a circle based on passed radius value
	 * @method calculate_area
	 * @param {float} Radius used to calculate the area
	 * @return {float} calculated area
	 */
	static float calculate_area(float radius){
		return M_PI * pow(radius, 2);
	}

	/**
	 * Calculates the circumference of a circle based on passed radius value
	 * @method calculate_circumference
	 * @param {float} Radius used to calculate the circumference
	 * @return {float} calculated circumference
	 */
	static float calculate_circumference(float radius){
		return 2 * M_PI * radius;
	}
public:
	/**
	 * Begins the class program
	 * @method begin
	 */
	static void begin(){
		bool isClosing = false;
		// print out welcome message
		print_header();

		// loop program
		while(!isClosing){
			isClosing = get_input();
		}

		//exit app
		print_exit();
	}

};

/**
 * Executes the app, on exception exit app with error notification
 */
int main(){
	try{
		// starts CircumferenceCalculator class
		CircleCalculator::begin();
	}catch(exception& e){
		// output error to user
		cout << "Exception occurred: " << e.what() << endl;
	}
	return 0;
}
