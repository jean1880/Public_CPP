#include <iostream>
#include <limits>
using namespace std;

bool PrintMessage(int,const float);
bool ValidLength(int);
int FindCount(int);

int main(){
	const int MAX = 3;
	int input, tries = 0;
	bool success = false;
	do{
		bool entered = false;
		do{
			if(entered){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}


			cout << "Please enter an integer between 4 to 7 digits" << endl;
			cin >> input;
		}while(ValidLength(input));

		int count = FindCount(input);
		cout << count << endl;

		if(count%2 == 0){
			success = PrintMessage(tries,MAX);
		}
		tries++;
	}while(tries <= MAX && !success);
	if(tries > MAX){
		PrintMessage(tries,MAX);
	}
	return 0;
}

bool ValidLength(int number){
	return !(number > 999 && number < 10000000);
}

int FindCount(int number){
	int count = number & 1 ? 1 : 0;
	while(number = number >> 1)
	{
		if(number & 1)
			count++;
	}
	return count;
}

bool PrintMessage(int tries, const float MAX){
	char successMessage[] = "Congratulations you've gained access";
	bool success = false;
	if(tries <= MAX){
		for(int i = 0; i <= (int)(sizeof(successMessage)/sizeof(*successMessage)); i++)
			cout << successMessage[i];
		cout << endl;
		success = true;
	}else{
		cout << "I’m sorry you've fail to input correctly " << MAX << " number of times" << endl;
	}

	return success;
}
