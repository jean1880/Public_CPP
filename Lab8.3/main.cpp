/**
 * Program sorts an array, then find an integer, and calculates the mean of the array
 * @author Jean-Luc Desroches
 */

#include "UserInterface.h"
#include "BubbleSort.h"
#include <iostream>

using namespace std;
int main(){
	cout << "Please enter the number of integers to sort: " << endl;
	int count = UserInterface::getIntegerInput();

	while(count <= 0){
		cout << "Please enter the number of integers to sort, value must be positive: " << endl;
		count = UserInterface::getIntegerInput();
	}

	int intArray[count];
	for(int i = 0; i < count; i++){
		cout << "Please enter integer " << (i+1) << ":" << endl;
		intArray[i] = UserInterface::getIntegerInput();
	}

	// show array to the user
	cout << "The array has " << count << " items" << endl;
	cout << "They array as entered was as follows:"<< endl << "{";
	for(int i = 0; i < count; i++){
		cout << " " << intArray[i];
	}

	cout << "}" ;
	int* output = BubbleSort::Sort(intArray, count, true);

	// show sorted array to the user
	cout << "The sorted array as entered was as follows:"<< endl << "{";
	for(int i = 0; i < count; i++){
		cout << " " << output[i];
	}

	cout << "}";
	return 0;
}
