// Name: Baljot Hansi

// declare the libraries being used
#include <iostream>
#include <string>

// using all assets under the std namespace
using namespace std;

// function prototypes
void inputGrades(double gradesTable[5][3]);
double getGrade(void);
void convertToLetter(double gradesTable[5][3], string letterTable[5][3]);
void printTable(string letterTable[5][3]);
double average(double gradesTable[5][3]);

int main()
{
	// declare local arrays:
	double gradeArray[5][3]; // array with numbered grades
	string letterArray[5][3]; // array with lettered grades
	double avg; // average to hold calculated average

	// call inputGrades function by passing in the numbered grade array
	inputGrades(gradeArray);

	// call converToLetter function by passing in the numbered grade array and the lettered grade array
	convertToLetter(gradeArray, letterArray);

	// call printTable function by passing in the lettered grade array
	printTable(letterArray);

	avg = average(gradeArray);
	cout << endl << "Course Average = " << avg << endl; // output the average

	// if the average is greater or equal to 60, the student passes
	if (avg >= 60)
	{
		cout << "Congratulations! You Passed the Academic Year!" << endl << endl;
	}
	// if the average is less than 60, the student fails
	else
	{
		cout << "You Fail! Better Luck Next Time!" << endl << endl;
	}
}

void inputGrades(double gradesTable[5][3])
{
	for (int i = 0; i < 5; i++) // loop through each row
	{
		for (int j = 0; j < 3;) // loop through each column
		{
			// request user to enter grades for a specific class
			cout << "Enter Grades for Class " << i + 1 << ":" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Enter Grade for Assignment (from 0 to 100): ";
			gradesTable[i][j++] = getGrade();
			cout << "Enter Grade for Midterm (from 0 to 100): ";
			gradesTable[i][j++] = getGrade();
			cout << "Enter Grade for Final (from 0 to 100): ";
			gradesTable[i][j++] = getGrade();
			cout << endl;
		}
	}
}

double getGrade(void)
{
	// declare local variables
	double grade;
	cin >> grade;
	
	// validate whether the grade is between 0 and 100, including 100
	while (grade <= 0 || grade > 100)
	{
		cout << "Invalid Grade. Try Again." << endl;
		cout << "Enter Grade (from 0 to 100): ";
		cin >> grade;
	}

	return grade;
}

void convertToLetter(double gradesTable[5][3], string letterTable[5][3])
{
	for (int i = 0; i < 5; i++) // loop through each row
	{
		for (int j = 0; j < 3; j++) // loop through each column
		{
			// check if numbered grade is between 95 and 100, all inclusive and assign A+ to lettered grade
			if (gradesTable[i][j] >= 95 && gradesTable[i][j] <= 100)
			{
				letterTable[i][j] = "A+";
			}
			// check if numbered grade is between 90 and 94, all inclusive and assign A to lettered grade
			else if (gradesTable[i][j] >= 90 && gradesTable[i][j] <= 94)
			{
				letterTable[i][j] = "A";
			}
			// check if numbered grade is between 80 and 89, all inclusive and assign B+ to lettered grade array
			else if (gradesTable[i][j] >= 85 && gradesTable[i][j] <= 89)
			{
				letterTable[i][j] = "B+";
			}
			// check if numbered grade is between 80 and 84, all inclusive and assign B to lettered grade array
			else if (gradesTable[i][j] >= 80 && gradesTable[i][j] <= 84)
			{
				letterTable[i][j] = "B";
			}
			// check if numbered grade is between 70 and 79, all inclusive and assign C to lettered grade array
			else if (gradesTable[i][j] >= 70 && gradesTable[i][j] <= 79)
			{
				letterTable[i][j] = "C";
			}
			// check if numbered grade is between 60 and 69, all inclusive and assign D to lettered grade array
			else if (gradesTable[i][j] >= 60 && gradesTable[i][j] <= 69)
			{
				letterTable[i][j] = "D";
			}
			// check if numbered grade is less than 60, assign F to lettered grade array
			else if (gradesTable[i][j] < 60)
			{
				letterTable[i][j] = "F";
			}
		}
	}
}

void printTable(string letterTable[5][3])
{
	cout << "***********************************************************************************************************************" << endl << endl;
	
	for (int i = 0; i < 5; i++) // loop through each row
	{
		// display course that the grades are being displayed for
		cout << "Course " << i + 1 << ": | ";
		for (int j = 0; j < 3; j++) // loop through each column
		{
			// display lettered grades
			cout << letterTable[i][j] << " | ";
		}
		cout << endl;
	}
}
double average(double gradesTable[5][3])
{
	double assignmentSum = 0, midtermSum = 0, finalSum = 0, average;
	for (int i = 0; i < 5; i++) // loop through each row
	{
		for (int j = 0; j < 3;) // loop through each column
		{
			assignmentSum += gradesTable[i][j++]; // sum up all the assignment grades
			midtermSum += gradesTable[i][j++]; // sum up all the midterm grades
			finalSum += gradesTable[i][j++]; // sum up all the final grades
		}
	}
	average = (assignmentSum / 5 * 0.15) + (midtermSum / 5 * 0.25) + (finalSum / 5 * 0.6); // calculate the average
	return average;
}