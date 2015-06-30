/**
 * Handles calculating sales values for Woody's Furniture
 * @author Jean-Luc Desroches
 */
#include <iostream>
using namespace std;

struct chair{
	string name;
	float price;
	int qtySold;
};

/**
 * Main class for woody's furniture
 * @class WoodyFurniture
 */
class WoodyFurniture{
private:
	const static string FURNITURE[3] = {
			"American Colonial",
			"Modern",
			"French Classical"
	};

	static int getQuantitySold(string furnitureName){
		unsigned int input;

		// output request message
		cout << "Please input the number of " << furnitureName << " sold:" << endl;

		// call this function until the user enters a valid value
		while(!(cin >> input)){
			cout << "Please enter a valid numeric value" << endl;
			input = getQuantitySold(furnitureName);
		}
		return input;
	}

public:
	static void begin(){

	}
};


int main() {
	WoodyFurniture::begin();
	return 0;
}
