/*
 * BubbleSort.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: jdesroches
 */

#include "BubbleSort.h"
#include <iostream>

namespace std {

BubbleSort::BubbleSort() {
	// TODO Auto-generated constructor stub

}

BubbleSort::~BubbleSort() {
	// TODO Auto-generated destructor stub
}
int* BubbleSort::Sort(int array[], int size, bool print){
	bool swap;
	int temp;
	int bottom = size- 1; // bottom indicates the end part of the
	int count, iteration = 0;
	// array where the largest values have
	// settled in order
	if(print){
		cout << endl << "Array Steps:" << endl;
	}

	do
	{

		cout << endl << "/******* Running through array, minus "<< iteration <<" iteration(s) *****/" << endl << endl;
		swap = false;
		for (count = 0; count < bottom; count++)
		{
			if (array[count] < array[count+1])
			{ // the next three lines do a swap
				if(print){
					cout << array[count] << " less than " << array[count+1] << " swapping position" << endl;
				}
				temp = array[count];
				array[count] = array[count+1];
				array[count+1] = temp;
				swap = true; // indicates that a swap occurred
			}
			else{
				if(print){
					cout << array[count] << " greater than or equal to " << array[count+1] << " maintaining position" << endl;
				}
			}
		}

		bottom--;
		iteration++;
		// the array adds one more value that is set in order
	} while(swap != false);
	if(print){
		cout << endl;
	}
	return array;
}

} /* namespace std */
