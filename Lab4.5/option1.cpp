/**
 * This program gets a user for their quarterly water bills for the last four quarters,
 * and returns their average output, and whether they should be using less water
 * @author Jean-Luc Desroches
 * @date 2015/05/24
 */

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Gets the users water bills for each quarter, calculates the average, and
 * tells the user whether their average is running too high
 * @class WaterProgram
 */
class WaterProgram{
private:
	float quarteylBill[4];

	/**
	 * Prints the welcome message
	 * @method printWelcomeMessage
	 */
	void printWelcomeMessage(){
		cout << '\\' << string(49, '*') << '\\' << endl;
		cout << '\\' << string(5, '*') << " Welcome to the the Water bill program " << string(5,'*') << '\\' << endl;
		cout << '\\' << string(49, '*') << '\\' << endl;
	}

	/**
	 * Runs the program through all functionality
	 * @method main
	 * @return {bool}
	 */
	bool main (){
		int i = 0;

		printWelcomeMessage();
		for(float value : quarteylBill){
			quarteylBill[i] = setBillValue(i);
			i++;
		}
		outputResults(calculateBillAverage());

		return checkMoreInputs();
	}

	/**
	 * Outputs the average amount of money the user spends on bills and whether that
	 * average is high, normal, or below the expected amount
	 * @method outputResults
	 * @param {float)
	 */
	void outputResults(float average){
		string waterState;

		if(average > 75){
			waterState = "You are using excessive amounts of water";
		}else if(average >= 25){
			waterState = "You are using a typical amount of water";
		}else{
			waterState = "Congratulations on your low water usage!";
		}

		cout << "Your average monthly bill is $" << fixed << setprecision(2) << average << ". " << waterState << endl;
	}

	/**
	 * Calculates the average amount the user spends on water and returns the value
	 * @method calculateBillAverage
	 * @return {float}
	 */
	float calculateBillAverage(){
		int i = 0;
		float total = 0;

		for(float value : quarteylBill){
			total += value;
			i++;
		}

		return (total / i);

	}

	/**
	 * Converts a string to lowercase
	 * @method toLower
	 * @param {&string}
	 */
	void toLower(string &data){
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	}

	/**
	 * Checks to see if the user has more bills to enter
	 * @method checkMoreInputs
	 * @return {bool}
	 */
	bool checkMoreInputs(){
		string reply;
		cout << "Do you wish to enter another bill set?" << endl;
		cin >> reply;
		return checkResponse(reply);
	}

	/**
	 * Checks the response and returns boolean value from response
	 * @param
	 * @return {bool}
	 */
	bool checkResponse(string res){
		// changes string characters to lowercase
		toLower(res);

		// check response
		if(res == "y" || res == "yes"){
			return true;
		}else if(res == "n" || res == "no"){
			return false;
		}else{
			// invalid input givin call recursively until valid response given
			cout << "Invalid option";
			return checkMoreInputs();
		}
	}

	/**
	 * Gets the value for a bill from a user
	 * @method setBillValue
	 * @param {int}
	 * @return {float}
	 */
	float setBillValue(int i){
		float bill;
		cout << "Please enter your bill for quarter " << i+1 << ':' << endl;

		// if the entered bill amount is not a valid input, recursively loop through the function until the correct value is entered
		if(!(cin >> bill)){
			cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			cout << "Please enter a numeric value for your bill" << endl;
			bill = setBillValue(i);
		}
		 return bill;
	}


public:
	/**
	 * starts the waterProgram
	 * @method begin
	 */
	void begin(){
		while(main()){};
	}
};


