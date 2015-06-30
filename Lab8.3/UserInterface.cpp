/*
 * UserInterface.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: jdesroches
 */

#include "UserInterface.h"
#include <string>
#include <iostream>
#include <limits>

namespace std {

UserInterface::UserInterface() {
	// TODO Auto-generated constructor stub

}

UserInterface::~UserInterface() {
	// TODO Auto-generated destructor stub
}

int UserInterface::getIntegerInput(){
	string input; int result;

	cin >> input;
	try{
		result = stoi(input);
	}catch(exception &e){
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter an integer" << endl;
		result = getIntegerInput();
	}
	return result;
}
} /* namespace std */

