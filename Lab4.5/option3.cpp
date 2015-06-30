/**
 * Calculates the total cost for a semester for a student incluiding boarding
 * @author Jean-Luc Desroches
 * @date 2015/05/24
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
/**
 * Main class runs program to calculate expenses and output results
 * @class UniversityExpense
 */
class UniversityExpense{
private:
	float OUT_OF_STATE_TUITION = 4500, IN_STATE_TUITION = 3000, OUT_OF_STATE_BOARD = 3500, IN_STATE_BOARD = 2500;
	char stateStatus;

	/**
	 * calculates the total expense for the semester
	 * @method calculateTotal
	 * @param {float}
	 * @param {float}
	 * @return {float}
	 */
	float calculateTotal(float tuition, float board){
		return (tuition + board);
	}

	/**
	 * Gets the tuition for the semester, based on whether the student is from out of state or
	 * in state
	 * @method getTuition
	 * @return {float}
	 */
	float getTuition(){
		string reply;
		cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
		cin >> reply;

		// check response code for valid input and returns tuition value, or calls this function until a valid choice is made
		if(reply == "I"){
			this->stateStatus = 'I';
			return IN_STATE_TUITION;
		}else if(reply == "O"){
			this->stateStatus = 'O';
			return OUT_OF_STATE_TUITION;
		}else{
			cout << "Invalid response" << endl;
			cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			return getTuition();
		}
	}

	/**
	 * Gets the cost of board, depending on whether the user wishes to board, and has indicated
	 * they are from out of state or in state
	 * @method getBoard
	 * @return {float}
	 */
	float getBoard(){
		string reply;

		cout << "Please input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
		cin >> reply;
		if(reply == "Y"){
			switch (stateStatus) {
				case 'I':
					return IN_STATE_BOARD;
				case 'O':
					return OUT_OF_STATE_BOARD;
			}
		}else if(reply == "N"){
			return 0;
		}else{
			cout << "Invalid response" << endl;
			cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			return getBoard();
		}
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
	 * Check whether the user wishes to continue using the program
	 * @return {bool}
	 */
	bool runAgain(){
		string reply;
		cout << "Calculate another tuition?" << endl;
		cin >> reply;
		toLower(reply);
		if(reply == "y" || reply == "yes"){
			return true;
		}else if(reply == "n" || reply == "no"){
			return false;
		}else{
			cout << "Invalid response" << endl;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			return runAgain();
		}
	}

	/**
	 * Runs all functionality for the class
	 * @method main
	 * @return {bool}
	 */
	bool main(){
		// get whether user is from in state or out of state
		// get whether user will need room and board or not
		 cout << "Your total bill for this semester is $" << fixed << setprecision(2) << calculateTotal(getTuition(),getBoard()) << endl;

		 return runAgain();
	}
public:
	void begin(){
		while(main());
	}
};


int main(){
	try{
		UniversityExpense universityExpense;
		universityExpense.begin();
		// exit program
		return 0;
	}catch(exception &e){ // catch any errors and output to user before exiting
		cout << e.what();
		return -1;
	}

}
