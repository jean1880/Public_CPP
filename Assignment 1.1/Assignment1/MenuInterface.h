#include <iostream>
#include <string>

namespace std{
	enum{
		HELP = -2,
		EXIT,
		FRACTION_CALCULATOR = 1,
		GRADING_SCHEMA,
		ARRAY_PROGRAM
	};

	void DisplayMenu(){
		cout << "Please select which program you wish to run, to exit type --exit, to show this menu again type --help" << endl
				<< "1) Fraction Calculator"<<endl
				<< "2) Grading Schema"<< endl
				<< "3) Array Program"<< endl
				<< "-e | --exit        Exits the program" << endl
				<< "-h | --help        Shows menu interface" << endl;
	}

	int CheckExit(string option){
		if(option == "-e" || option == "--exit"){
			return -1;
		}else if(option == "-h" || option == "--help"){
			return -2;
		}
		return -3;
	}

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
