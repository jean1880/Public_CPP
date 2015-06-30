/**
 * This program calculates the perimeter and area of a rectangle, given a radius
 * @author Jean-Luc Desroches
 * @date 05/04/2015
 */
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Class handles calculating the perimeter and area of a rectangle, based on a user's input
 * @class RectangleCalculator
 */
class RectangleCalculator{
private:

	/**
	 * Prints the application header to the console
	 * @method print_header
	 */
	static void print_header(){
		cout << "/******************************************************************/" << endl;
		cout << "/***************** Beginning Rectangle Calculator *****************/" << endl;
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
	 * Gets the user to input the value of the rectangles's side measurement, will continue to ask until the input is valid
	 * @method get_radius
	 * @return {float} Radius entered by user
	 */
	static float get_side(string sideName){
		bool isValid = false;
		float input;

		// get users input on rectangles's side measurement, if is not a valid input, ask again
		while(!isValid){
			cout << "what is the "<< sideName <<" of the rectangle? ";
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
		float length = get_side("length"),
				width = get_side("width");

		cout << "The perimeter of the rectangle is: " << calculate_perimeter(length, width) << endl;
		cout << "The area of the rectangle is: " << calculate_area(length, width) << endl;

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
	 * Calculates the perimeter of a rectangle based on passed length and width
	 * @method calculate_perimeter
	 * @param {float} length used to calculate the perimeter
	 * @param {float} width used to calculate the perimeter
	 * @return {float} calculated perimeter
	 */
	static float calculate_perimeter(float length,float width){
		return 2 * (length + width);
	}

	/**
	 * Calculates the area of a rectangle based on passed length and width
	 * @method calculate_perimeter
	 * @param {float} length used to calculate the perimeter
	 * @param {float} width used to calculate the perimeter
	 * @return {float} calculated perimeter
	 */
	static float calculate_area(float length, float width){
		return length * width;
	}
public:
	/**
	 * Begins the class program
	 * @method begin
	 */
	static void begin(){
		// print out welcome message
		print_header();

		// loop program
		while(!get_input());

		//exit app
		print_exit();
	}

};

/**
 * Executes the app, on exception exit app with error notification
 */
int main(){
	try{
		// starts RectangleCalculator class
		RectangleCalculator::begin();
	}catch(exception& e){
		// output error to user
		cout << "Exception occurred: " << e.what() << endl;
	}
	return 0;
}
