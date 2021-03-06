/**
 * Handles question 2 of the assignment
 * @author Jean-Luc Desroches
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


namespace std{
	/**
	 * Prints out welcome message to the user
	 * @method PrintWelcomeMessage
	 */
	void PrintGradingWelcomeMessage(){
		cout << '/' << string(50, '*') << '/' << endl;
		cout << "/*******" << " Welcome to the Grading Schema Program " << "*******/" << endl;
	}

	/**
	 * Parses the input of the user, pulling out the values from the line in the file
	 * @method ParseLine
	 * @param {string} line
	 * @return {vector<string>}
	 */
	vector<string> ParseLine(string line){
		vector<string> details;
		string delimiter = " ";
		size_t pos = 0;
		string token;

		unsigned int x = 0;
		while ((pos = line.find(delimiter)) != string::npos) {

			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			details.push_back(token);
			x++;
		}
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		details.push_back(line);
		return details;
	}

	/**
	 * Calculates the average of a student from vector collection of a line, averaage is returned by reference
	 * @method CalculateAverage
	 * @param {vector<string>} student
	 * @param {int} grades
	 * @param {float} average
	 */
	void CalculateAverage (vector<string> student, int grades, float &average){
		float sum = 0;

		for(int i = 0; i < grades; i++){
			sum += stoi(student[i+1]);
		}

		average = sum/grades;
	}

	/**
	 * Calculates the grade value based on grade of student
	 * @methos CalculateGrade
	 * @param {const int}
	 * @return {char}
	 */
	char CalculateGrade(const int grade){
		char value;
		if( grade >= 90){
			value = 'A';
		}else if(grade >= 80){
			value = 'B';
		}else if(grade >= 70){
			value = 'C';
		}else if(grade >= 60){
			value = 'D';
		}else{
			value = 'F';
		}
		return value;
	}

	/**
	 * Prints out the averages of each test
	 * @method PrintAverages
	 * @param {vector<float>} testAverages
	 * @param {vector<float>} studentAverages
	 * @param {int} students
	 * @param {int} tests
	 * @param {const int} formatWidth
	 */
	void PrintAverages(vector<float> testAverages, vector<float> studentAverages, int students, int tests, const int formatWidth){
		cout << setw(formatWidth) << "test avg";
		for(int i = 0; i < tests; i++){
			cout << setw(formatWidth) << testAverages[i];
		}

		float sum = 0;
		// calculate student total average
		for(int i = 0; i < students; i++){
			sum += studentAverages[i];
		}
		cout << setw(formatWidth) << sum/students << endl;
	}

	/**
	 * Prints out grades of the student to the table
	 * @method PrintGrades
	 * @param {int} grades
	 * @param {vector<string>} studentGrades
	 * @param {float} studentAverage
	 * @param {char} grade
	 * @param {const int} formatWidth
	 */
	void PrintGrades(int grades, vector<string> studentGrades, float studentAverage, char grade, const int formatWidth){
		cout << setw(formatWidth) << studentGrades[0];

		for(int y = 0; y < grades; y++){
			cout << setw(formatWidth) << studentGrades[y+1];
		}

		cout << setw(formatWidth) << studentAverage << setw(formatWidth) << grade << endl;
	}

	/**
	 * Updates running tally of test scores by reference
	 * @method UpdateTotals
	 * @param {vector<string>} studentGrades
	 * @param {int} tests
	 * @param {vector<float>} test totals
	 */
	void UpdateTotals(vector<string> studentGrades, int tests, vector<float> &testTotals){
		for(int i = 0; i < tests; i++){
			testTotals[i] += stoi(studentGrades[i+1]);
		}
	}

	/**
	 * Calculates total average of each test
	 * @method calculateTestAvg
	 * @param {vector<float>} totals
	 * @param {int} totalStudents
	 * @param {int} totalTests
	 * @param {vector<float>} testAverages
	 */
	void calculateTestAvg(vector<float> totals, int totalStudents, int totalTests, vector<float> &testAverages){
		for(int i = 0; i < totalTests; i++){
			testAverages[i] = totals[i]/totalStudents;
		}
	}

	/**
	 * Gets all the grades of the students from a file, and calculates thheir averages, and total averages and outputs it to the screen
	 * @method CalculateGrades
	 * @param {string} target
	 */
	void CalculateGrades(string target){
		string line;
		ifstream file;
		int details[2];
		const int formatWidth = 8;
		vector<string> studentGrades;
		vector<float> testTotals, testAverages, studentAverages;
		file.open(target);
		// try and open target file
		unsigned int i = 0;
		while ( getline (file,line) )
		{
			if(i==0){
				vector<string> temp = ParseLine(line);
				details[0] = stoi(temp[0]);
				details[1] = stoi(temp[1]);
				cout << setw(formatWidth) << "Name";
				for(int y = 0; y < details[1]; y++){
					testTotals.push_back(0);
					testAverages.push_back(0);
					cout << setw(formatWidth) << "Test" + to_string(y);
				}
				cout << setw(formatWidth) << "AVG" << setw(formatWidth) << "Grade" << endl;
			}else{
				studentGrades = ParseLine(line);

				// calculate average grade of the student
				float studentAverage;
				CalculateAverage(studentGrades, details[1], studentAverage);
				studentAverages.push_back(studentAverage);

				// add grade values to running total
				UpdateTotals(studentGrades, details[1], testTotals);

				// calculate grade value from average
				char grade = CalculateGrade((const int)studentAverage);
				PrintGrades(details[1], studentGrades, studentAverage, grade, formatWidth);
			}

			i++;
		}
		// close file when done
		file.close();

		// calculate test averages
		calculateTestAvg(testTotals, details[0], details[1], testAverages);

		// print out total averages
		PrintAverages(testAverages, studentAverages, details[0], details[1], formatWidth);
	}
}
