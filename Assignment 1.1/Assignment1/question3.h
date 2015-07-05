/**
 * Question 3 solution, due to time, abandoned final mile on this question, it is sorting the valujes, and will grab highest value and 
 * place it up froont but had trouble getting it to properly sort all of the values as needed.
 * @author Jean-Luc Desroches
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>

namespace std{
	/**
	 * Displays this programs menu to the user
	 * @method ShowArrayMenu
	 */
	void ShowArrayMenu(){
		cout << "/************** Array Max Sort **************/" << endl;
		cout << "/* This program takes an array of integers    */" << endl;
		cout << "/* and sorts them into the largest possible   */" << endl;
		cout << "/* number                                     */" << endl;
		cout << "/* -e | --exit      Exits the program         */" << endl;
		cout << "/* -h | --help      Shows this menu again     */" << endl;
		cout << "/* -r | --run       Calculates largest number */" << endl;
		cout << "/**********************************************/" << endl;
	}

	/**
	 * Sorts the array of integers to build the largest possible number (Could not get this fully working)
	 * @method SortValues
	 * @param {vector<int>} integerArray
	 * @return {vector<int>}
	 */
	vector<int> SortValues(vector<int> integerArray){
		vector<int> sortedIntegers;

		int max = 0;
		// loop through each integer in the array
		for(int i = integerArray.size() - 1; i >= 0; i--){
			int tens = integerArray[i] / 10, ones = integerArray[i] % 10;
			if(tens > max){ // if there was a tens column value, and it is the largest number available, set the first number in the sorted array with this value
				max = tens;
				sortedIntegers.insert(sortedIntegers.begin(),integerArray[i]);
			}else if(tens == 0 && ones > max){
				max = ones;
				sortedIntegers.insert(sortedIntegers.begin(),integerArray[i]);
			}else{
				for(int x = sortedIntegers.size() - 1; x >= 0; x--){
					int tens_sub = sortedIntegers[x] / 10, ones_sub = sortedIntegers[x] % 10;
					if(tens > 0 && tens_sub > tens){
						sortedIntegers.insert(sortedIntegers.begin() + x,integerArray[i]);
						break;
					}else if(tens != 0 && tens == tens_sub && ones_sub > ones){
						sortedIntegers.insert(sortedIntegers.begin() + x, integerArray[i]);
						break;
					}else if(tens == 0 && tens_sub == 0 && ones_sub > ones){
						sortedIntegers.insert(sortedIntegers.begin() + x, integerArray[i]);
						break;
					}else{
						sortedIntegers.push_back(integerArray[i]);
						break;
					}
				}
			}
		}

		return sortedIntegers;
	}

	/**
	 * Gets input from the user, and checks if the user wishes to access the menu, exit the program, or sort the values, if none of theses, return the integer inputed
	 * @method GetInput
	 * @return {int}
	 */
	int GetInput(){
		string input;
		int value;
		try{
			cout << "Please enter an integer for the array" << endl;
			cin >> input;
			if(input == "-e" || input == "--exit"){ // exit program
				value = -1;
			}else if(input == "-h" || input == "--help"){ // show menu again
				value = -2;
			}else if(input == "-r" || input == "--run"){ // show menu again
				value = -3;
			}else{
				value = stoi(input);
				if(value <= 0 || value > 99){
					cout << "Input must be a positive value between 1-99" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					value = GetInput();
				}
			}
		}catch(invalid_argument &e){
			// invalid entry recall for get input
			cout << "Input must be an integer to be valid" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			value = GetInput();
		}catch(out_of_range &e){
			cout << "Integer is too large to be processed, please enter a smaller value" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			value = GetInput();
		}

		return value;
	}

	/**
	 * Runs quesiton 3 in a loop until exit command is given
	 * @method RunQuestion3
	 */
	bool RunQuestion3(){
		vector<int> integerArray;

		ShowArrayMenu();
		int input;

		// get integers and add the to vector
		while((input = GetInput()), input != -1){
			if(input == -2){
				ShowArrayMenu();
			}else if(input == -3){
				if(integerArray.size() > 1){
					integerArray = SortValues(integerArray);
					for(unsigned int i = 0; i < integerArray.size(); i++){
						cout << integerArray[i];
					}
					cout << endl;
					integerArray.clear();
				}else{
					cout << "You need at least two integers before the calculation can run" << endl;
				}
			}else{
				integerArray.push_back(input);
			}
		}

		return false;
	}
}
