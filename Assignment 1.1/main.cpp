#include "question1.h"
#include "MenuInterface.h"
// question 3 http://ideone.com/4lX6Gb

namespace std{
	bool MenuInterface();
	void DoQuestion1();
}

int main(){
	while(std::MenuInterface());
	return 0;
}

namespace std{
	void DoQuestion1(){
		const unsigned int FRACTION_COUNT = 2;
		vector<int> fraction[FRACTION_COUNT];
		const char separator    = ' ';
		const int cellWidth     = 14;

		// print welcome message to the user
		PrintWelcomeMessage();

		// get fractions from user
		for(unsigned int i = 0; i < FRACTION_COUNT; i++){
			GetFraction((int)(i + 1), fraction[i]);
			PrintFraction((int)(i + 1), fraction[i]);
		}

		PrintTableHead(cellWidth,separator);
		// calculate each mathematical operation
		for(int i = 0; i < 4; i++){
			char operand = ' ';
			vector<int> result;
			GetCalculation(i, fraction, operand, result);
			PrintTableLine(fraction,result,operand,cellWidth,separator);
		}
	}

	bool MenuInterface(){
		DisplayMenu();
		int selected = GetOption();

		switch(selected){
		case HELP:
			MenuInterface();
			break;
		case EXIT:
			cout << "Exiting..." << endl;
			return false;
			break;
		case FRACTION_CALCULATOR:
			// perform first question
			std::DoQuestion1();
			break;
		default:
			cout << "Option not recognized" << endl;
			MenuInterface();
		}
		return true;
	}
}
