/**
 * This file handles question one, and performs multiplication, division, subtraction and addition
 * of two fraction provided by the user
 * @author Jean-Luc Desroches
 * @date 06/22/2015
 */

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <vector>


/**
 * Methods and functions of resolving the assignment
 */
namespace std{

	// enumerator to label ints in switch statement
	enum{
		DIVIDE,
		MULTIPLY,
		SUBTRACT,
		ADD
	};

	/**
	 * Finds the largest common divisor of ttwo integers
	 * @method GreatestCommonDivisor
	 * @param {int}
	 * @param {int}
	 * @return {int}
	 */
	int GreatestCommonDivisor(int x,int y)
	{
	  if(y==0)  // base case, the programs stops if y reaches 0.
		 return x;     //it returns the GCD
	  else
		return GreatestCommonDivisor(y,x%y); //if y doesn't reach 0 then recursion continues
	}

	/**
	 * Finds the lowest common multiple of two ints
	 * @method LowestCommonMultiple
	 * @param {int}
	 * @param {int}
	 * @return {int}
	 */
	int LowestCommonMultiple(int x,int y)
	{
	  int prod;
	  if(y%x==0)
		 return y;
	  else
	  {
		 prod=x*y;
		 while(x!=y) // get the GCD of 2 given integers
		 {
			if(x>y)
			   x=x-y;
			else
			   y=y-x;   //x now is the GCD
		 }
		 return LowestCommonMultiple(y,prod/x);  //recurse, changing x to y and vice versa
	  }   //LCM = (x*y)/(GCD)
	}

	/**
	 * Converts a fraction to it's lowest common multiple
	 * @method ConvertFraction
	 * @param {vector<int>}
	 * @param {int}
	 * @return {vector<int>}
	 */
	vector<int> ConvertFraction(vector<int> fraction, int LCM){
	   float calc = LCM/fraction[1];

	   fraction[0] = fraction[0] * calc;
	   fraction[1] = fraction[1] * calc;
	   return fraction;
	}

	/**
	 * Gets a fraction, must be positive unless overloaded with bool true
	 * @method GetFraction
	 * @param {string} message Prompt displayed to user for input
	 * @param {bool} allowNegatives [OPTIONAL] If true, allows for user to enter a negative value
	 */
	vector<int> GetFractionInput(string message){
		vector<int> output;
		cout << message << endl;

		// try to get input, and ensure input is an integer
		try{
			string value;
			cin >> value;

			// clear cin in case function is called again
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string delimiter = "/";

			size_t pos = 0;
			string token;

			int i = 0;
			while ((pos = value.find(delimiter)) != string::npos) {

				token = value.substr(0, pos);
			    value.erase(0, pos + delimiter.length());

			    output.push_back(stoi(token));

			    i++;
			}

			output.push_back(stoi(value));
		}catch(invalid_argument &e){ // input was not an integer
			cout << "Invalid value entered, please enter a valid value to continue" << endl;
			output = GetFractionInput(message);
		}catch(out_of_range &o){
			cout << "Value was out of range for an integer, please enter a valid value to continue" << endl;
			output = GetFractionInput(message);
		}catch(exception &e){
			exit (EXIT_FAILURE);
		}

		return output;
	}

	/**
	 * Get a fraction set
	 * @method GetFraction
	 * @param {int} count Fraction count to display to user
	 * @param {int[2]} fraction Fraction value to fill by reference
	 */
	void GetFraction(int count, vector<int> &fraction){
		fraction = GetFractionInput("Please enter fraction " + to_string(count));
		if(fraction[1] <= 0){
			cout << "The denominator cannot be a negative value, or equal to 0" << endl;
			GetFraction(count, fraction);
		}
	}

	/**
	 * Runs calculation specified by int selector and sets the operand symbol, and result parameters
	 * @method GetCalculation
	 * @param {int} calculation integer specifies witch calculation to perform
	 * @param {int[2][2]} fraciton Two fraction to perform calculation on
	 * @param {char} operand Operand symobol to be set, passed by reference
	 * @param {int[2]} result Result from calculation, passed by reference
	 */
	void GetCalculation(int calculation, vector<int> (&fraction)[2], char &operand, vector<int> &result){
		int LCM;
		vector<int> temp[2];
		// get calculation to perform
		switch(calculation){
			case DIVIDE:
				operand = '/';
				// multiply with reciprocal
				result.push_back(fraction[0][0] * fraction[1][1]);
				result.push_back(fraction[0][1] * fraction[1][0]);

				break;
			case MULTIPLY:
				operand = '*';
				// multiply with reciprocal
				result.push_back(fraction[1][0] * fraction[0][0]);
				result.push_back(fraction[1][1] * fraction[0][1]);

				break;
			case SUBTRACT:
				operand = '-';
				LCM = LowestCommonMultiple(fraction[1][1], fraction[0][1]);

				temp[0]= ConvertFraction(fraction[0], LCM);
				temp[1]= ConvertFraction(fraction[1], LCM);

				result.push_back(temp[0][0] - temp[1][0]);
				result.push_back(temp[0][1]);
				break;
			case ADD:
				operand = '+';
				LCM = LowestCommonMultiple(fraction[1][1], fraction[0][1]);

				temp[0]= ConvertFraction(fraction[0], LCM);
				temp[1]= ConvertFraction(fraction[1], LCM);

				result.push_back(temp[1][0] + temp[0][0]);
				result.push_back(temp[1][1]);
				break;
			default:
				break;
		};


		int div = GreatestCommonDivisor(result[0], result[1]);
		result[0] = result[0]/div;
		result[1] = result[1]/div;
	}

	/**
	 * Prints out a message with what fraction they entered
	 * @method PrintFraction
	 * @param {int}
	 * @param {vector<int>}
	 */
	void PrintFraction(int count, vector<int> fraction){
		cout << "Fraction " << count << ": " << fraction[0] << "/" << fraction[1] << endl;
	}

	/**
	 * Prints out the table header
	 * @method PrintTableHead
	 * @param {const int}
	 * @param {const char}
	 */
	void PrintTableHead(const int cellWidth, const char separator){
		cout << endl << "/******************** " << "Results" << " *********************/" << endl;
		cout << left << setw(cellWidth) << setfill(separator) << "Fraction 1";
		cout << left << setw(cellWidth) << setfill(separator) << "Fraction 2";
		cout << left << setw(cellWidth) << setfill(separator) << "Operand";
		cout << left << setw(cellWidth) << setfill(separator) << "Result" << endl;
	}

	/**
	 * Prints out a table line with the two fraction the user entered, the operation performed and the result
	 * @method PrintTableLine
	 * @param {vector<int>[2]}
	 * @param {vector<int>}
	 * @param {char}
	 * @param {const int}
	 * @param {const char}
	 */
	void PrintTableLine(vector<int> fraction[2], vector<int> result, char operand, const int cellWidth, const char separator){
		cout << left << setw(cellWidth) << setfill(separator) << to_string(fraction[0][0]) + '/' + to_string(fraction[0][1]);
		cout << left << setw(cellWidth) << setfill(separator) << to_string(fraction[1][0]) + '/' + to_string(fraction[1][1]);
		cout << left << setw(cellWidth) << setfill(separator) << operand;
		cout << left << setw(cellWidth) << setfill(separator) << to_string(result[0]) + '/' + to_string(result[1]) << endl;
	}

	/**
	 * Prints out welcome message to the user
	 * @method PrintWelcomeMessage
	 */
	void PrintWelcomeMessage(){
		cout << '/' << string(50, '*') << '/' << endl;
		cout << "/*******" << " Welcome to the Fraction Calculator " << "*******/" << endl;
	}
}

