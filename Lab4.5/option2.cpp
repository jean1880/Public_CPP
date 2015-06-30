/**
 * Returns value of shirts based on the number of shirts the user is purchasing
 * @author Jean-Luc Desroches
 * @date 2015/05/24
 */

#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;
/**
 * Gets the number of shirts being sold, and calculates the total value, including a discount based on the quantities sold
 */
class ShirtCalculator{
private:
	const float SHIRT_VALUE = 12,  SMALL_DISCOUNT = 5, MEDIUM_DISCOUNT = 10,
	LARGE_DISCOUNT = 20, BULK_DISCOUNT = 30, SMALL_DISCOUNT_VALUE = 0.10, MEDIUM_DISCOUNT_VALUE = 0.15,
	LARGE_DISCOUNT_VALUE = 0.20, BULK_DISCOUNT_VALUE = 0.25;
	/**
	 * Gets the number of shirts being sold to the user
	 * @method getNumberofShirts
	 * @return {int}
	 */
	int getNumberofShirts(){
		int shirts;

		cout << "How many shirts would you like?" << endl;
		if(!(cin >> shirts) || shirts < 1){
			cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		    cout << "Please enter a valid numeric value" << endl;
		    shirts = getNumberofShirts();
		}

		return shirts;
	}

	/**
	 * Outputs the cost per shirt and the total to the user
	 * @param {int}
	 */
	void outputTotal(int shirtsSold){
		float costPerShirt = returnShirtValue(shirtsSold);
		cout << "The cost per shirt is $" << fixed << setprecision(2) << costPerShirt <<  " and the total is $" << calculateTotal(shirtsSold, costPerShirt) << endl;
	}

	/**
	 * Calculates the total based on number of shirts sold and shirt value
	 */
	float calculateTotal(int shirtsSold, float costPerShirt){
		return (shirtsSold * costPerShirt);
	}

	/**
	 * Returns the cost per shirt
	 * @method returnShirtValue
	 * @param {int}
	 * @return {float}
	 */
	float returnShirtValue(int shirtsSold){
		if(shirtsSold > BULK_DISCOUNT){
			return calculateShirtValue(shirtsSold, BULK_DISCOUNT_VALUE);
		}else if(shirtsSold > LARGE_DISCOUNT){
			return calculateShirtValue(shirtsSold, LARGE_DISCOUNT_VALUE);
		}else if(shirtsSold > MEDIUM_DISCOUNT){
			return calculateShirtValue(shirtsSold, MEDIUM_DISCOUNT_VALUE);
		}else if(shirtsSold > SMALL_DISCOUNT){
			return calculateShirtValue(shirtsSold, SMALL_DISCOUNT_VALUE);
		}else{
			return SHIRT_VALUE;
		}
	}

	/**
	 * Calculates the shirts value with the discount
	 * @method calculateShirtValue
	 * @param {int}
	 * @param {float}
	 */
	float calculateShirtValue(int shirtsSold, float discount){
		return ( SHIRT_VALUE * (1 - discount));
	}

	/**
	 * Converts a string to lowercase
	 * @method toLower
	 * @param {&string}
	 */
	void toLower(string &data){
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	}


	/**
	 * Check whether the user wishes to continue using the program
	 * @return {bool}
	 */
	bool runAgain(){
		string reply;
		cout << "Sell some more shirts?" << endl;
		cin >> reply;
		toLower(reply);
		if(reply == "y" || reply == "yes"){
			return true;
		}else if(reply == "n" || reply == "no"){
			return false;
		}else{
			cout << "Invalid response" << endl;
			cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			return runAgain();
		}
	}

	/**
	 * Runs all functionality for the class
	 * @method main
	 * @return {bool}
	 */
	bool main(){
		// get number of shirts being sold and return cost per shirt and total
		outputTotal(getNumberofShirts());

		return runAgain();
	}
public:
	void begin(){
		while(main());
	}
};

