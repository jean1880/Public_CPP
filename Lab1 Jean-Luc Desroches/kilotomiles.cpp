// Jean-Luc Desroches
// 05/04/2015
// Converts kilometers to miles

#include <iostream>
using namespace std;

class conversion{
	private:
		static const float CONVERSION_VALUE = 0.621371;

	public:

		static float ConvertToMiles(float km){
			float miles;
			miles = km * CONVERSION_VALUE;

			return miles;
		}
};


int main(){
	float input;
	bool valid =false;

	while(!valid){
		cout << "Enter kilometers: " << endl;
		cin >> input;
		if(input != 0){
			valid = true;
		}
	}

	cout << "Miles: " << conversion::ConvertToMiles(input) << endl;
}
