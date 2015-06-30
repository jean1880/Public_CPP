/**
 * This program will determine the batting average of a player.
 * The number of hits and at bats are set internally in the program.
 * @author Jean-Luc Desroches
 * @date 05/12/2015
 */

#include <iostream>


using namespace std;
const int AT_BAT = 421;
const int HITS = 123;
int main()
{
	float batAvg;
	batAvg = (float)(HITS / AT_BAT);
	cout << "The batting average is " << batAvg << endl;
	return 0;
}
