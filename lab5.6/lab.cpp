/**
 * Allows user to enter the number of days that various tellers missed over three years
 * @author Jean-Luc Desroches
 * @date 06/01/2015
 */
#include <iostream>

using namespace std;
int main(){
	int numTellers, totalDays;

	cout << "How Many tellers worked at Nation's Bank during each of the last three years?" << endl;
	cin >> numTellers;

	for(int year = 0; year < 3; year++){
		for(int i = 0; i < numTellers; i++){
			int days;
			cout << "How many days was teller " << i + 1
					<< " out sick during year " << year + 1
					<< "?" << endl;
			cin >> days;

			totalDays += days;
		}
	}

	if(numTellers > 0){
		cout << "The " << numTellers << " tellers were out sick for a total of " << totalDays
				<< " days during the last 3 years." << endl;
	}

	return 0;
}
