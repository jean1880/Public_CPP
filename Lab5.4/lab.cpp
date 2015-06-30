// This program finds the average time spent programming by a student
// each day over a three day period.
// PLACE YOUR NAME HERE
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{

	float numHours, total, average;
	int student,day = 0; // these are the counters for the loops
	string classes[2] = {
			"programming",
			"biology"
	};

	for(int i = 0; i < size_t(classes); i++){
		int numStudents, numDays;
		cout << "This program will find the average number of hours a day"
					<< " that a student spent doing "<< classes[i] <<" over a long weekend\n\n";
			cout << "How many students are there ?" << endl << endl;
			cin >> numStudents;

			cout << "Please enter the number of days in the long weekend" << endl;
			cin >> numDays;

			for(student = 1; student <= numStudents; student++)
			{
				total = 0;
				for(day = 1; day <= numDays; day++)
				{
					cout << "Please enter the number of hours worked by student "
						<< student <<" on day " << day << "." << endl;
					cin >> numHours;
					total = total + numHours;
				}
				average = total / 3;
				cout << endl;
				cout << "The average number of hours per day spent programming by "
					<< "student " << student << " is " << average
					<< endl << endl << endl;
			}

	}

	return 0;
}

template<class T, size_t N>
size_t size(T (&)[N]) { return N; }
