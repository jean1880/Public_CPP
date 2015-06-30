/*
 * UserInterface.h
 *
 *  Created on: Jun 8, 2015
 *      Author: jdesroches
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

namespace std {

class UserInterface {
public:
	UserInterface();
	virtual ~UserInterface();
	static int getIntegerInput();
};

} /* namespace std */

#endif /* USERINTERFACE_H_ */
