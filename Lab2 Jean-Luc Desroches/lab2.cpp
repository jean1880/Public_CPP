// This program demonstrates the use of characters and strings
// PLACE YOUR NAME HERE
#include <iostream>
#include <string>
using namespace std;
// Definition of constants
const string FAVORITESODA = "Dr. Dolittle"; // use double quotes for strings
const char BESTRATING = 'A';
// use single quotes for characters
int main()
{
	char rating = 'B';
	string favoriteSnack = "crackers";
	int numberOfPeople = 250;
	int topChoiceTotal = 148;

	//Assign the value of "crackers" to favoriteSnack
	//Assign a grade of 'B' to rating
	//Assign the number 250 to the numberOfPeople
	//Assign the number 148 to the topChoiceTotal
	// Fill in the blanks of the following:
	cout << "The preferred soda is " << FAVORITESODA << endl;
	cout << "The preferred snack is " << favoriteSnack	<< endl;
	cout << "Out of " << numberOfPeople << " people " << topChoiceTotal	<< " chose these items!" << endl;
	cout << "Each of these products were given a rating of " << BESTRATING << " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << rating << endl;
	;
	return 0;
}
