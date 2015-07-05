/**
 * Question 3 solution
 * @author Jean-Luc Desroches
 */

#include <iostream>
#include <string>
#include <limits>

namespace std{
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

	void InsertIntoSortedValues(vector<int> &sortedIntegers, int integer, int n){
		if(sortedIntegers.size() == 0 || n == 0){
			sortedIntegers.push_back(integer);
		}else if(integer > sortedIntegers[n]){
			sortedIntegers.insert(sortedIntegers.begin() + n,integer);
		}else if(integer == sortedIntegers[n]){
			sortedIntegers.insert(sortedIntegers.begin() + (n-1),integer);
		}else{
			InsertIntoSortedValues(sortedIntegers, integer, n-1);
		}
	}

	vector<int> SortValues(vector<int> integerArray){
		vector<int> sortedIntegers;

		int max = 0;
		for(int i = integerArray.size() - 1; i >= 0; i--){
			int tens = integerArray[i] / 10, ones = integerArray[i] % 10;
			if(tens > max){
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
					}else if(tens == 0 && tens_sub ==0 && ones_sub > ones){
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
