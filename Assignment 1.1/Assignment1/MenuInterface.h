/**
 * This is the main menu interface of the application, and handles user's iinputs to access various components of the assignment
 * @author Jean-Luc Desroches
 */

#include <iostream>
#include <string>

namespace std{
	/**
	 * Simple enumerator, to label integer options
	 */
	enum{
		HELP = -2,
		EXIT,
		FRACTION_CALCULATOR = 1,
		GRADING_SCHEMA,
		ARRAY_PROGRAM
	};

	/**
	 * Outputs the menu options to the user
	 * @method DisplayMenu
	 */
	void DisplayMenu(){
		cout << "Please select which program you wish to run, to exit type --exit, to show this menu again type --help" << endl
				<< "1) Fraction Calculator"<<endl
				<< "2) Grading Schema"<< endl
				<< "3) Array Program"<< endl
				<< "-e | --exit        Exits the program" << endl
				<< "-h | --help        Shows menu interface" << endl;
	}

	/**
	 * Check if user has requested to exit, or show menu, otherwise, return -3 to flag a continue parameter
	 * @method CheckExit
	 * @param {string} option  User menu input
	 * @return {int}
	 */
	int CheckExit(string option){
		if(option == "-e" || option == "--exit"){
			return -1;
		}else if(option == "-h" || option == "--help"){
			return -2;
		}
		return -3;
	}

	/**
	 * Gets input from the user, on which option they wish to run, returns the selected input as an integer option
	 * @method GetOption
	 * @return {int}
	 */
	int GetOption(){
		string option;
		cin >> option;
		int selected = CheckExit(option);
		try{
			if(selected == -3){
				selected = stoi(option);
			}
		}catch(invalid_argument &e){
			selected = -3;
		}

		return selected;
	}
}
