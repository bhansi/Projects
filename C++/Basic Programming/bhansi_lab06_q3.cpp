// Name: Baljot Hansi

// declare the libraries being used
#include <iostream>
#include <string>

// using all assets under the std namespace
using namespace std;

// function prototypes
int myRandom(void);
void printArray(int Array[], int size);
double myAverage(int Array[], int size);
int myMax(int Array[], int size);
int myMin(int Array[], int size);
void reverseArray(int Array[], int size);

int Array2[10];

int main()
{
	const int size = 10;
	int myArray[size];
	int integer;
	char choice;

	while (true)
	{
		cout << "Enter an Integer: ";
		cin >> integer;

		cout << endl;

		for (int i = 0; i < size; i++)
		{
			myArray[i] = integer * myRandom();
		}

		printArray(myArray, size);

		cout << endl << "Average = " << myAverage(myArray, size) << endl << endl;

		cout << "Max = " << myMax(myArray, size) << endl;
		cout << "Min = " << myMin(myArray, size) << endl << endl;

		cout << endl;

		reverseArray(myArray, size);

		cout << endl << "Would You Like to Play Again (y/n)? ";
		cin >> choice;
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Invalid Choice. Try Again." << endl;
			cout << endl << "Would You Like to Play Again (y/n)? ";
			cin >> choice;
		}
		if (choice == 'n' || choice == 'N')
		{
			break;
		}
		cout << endl;
	}
	cout << endl << "Thanks for Playing." << endl << endl;
}

int myRandom(void)
{
	int random = rand() % 8;
	return random;
}

void printArray(int Array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Array[" << i << "] = " << Array[i] << endl;
	}
}

double myAverage(int Array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += Array[i];
	}
	return double(sum) / size;
}

int myMax(int Array[], int size)
{
	int maximum = Array[0];
	for (int i = 0; i < size; i++)
	{
		if (maximum < Array[i])
		{
			maximum = Array[i];
		}
	}
	return maximum;
}

int myMin(int Array[], int size)
{
	int minimum = Array[0];
	for (int i = 0; i < size; i++)
	{
		if (minimum > Array[i])
		{
			minimum = Array[i];
		}
	}
	return minimum;
}

void reverseArray(int Array[], int size)
{
	int j = 9;

	for (int i = 0; i < size; i++)
	{
		Array2[i] = Array[j--];
	}
	printArray(Array2, 10);
}