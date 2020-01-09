// Name: Baljot Hansi, Date: November 25, 2018, Section: 55

// Display factorials of 1 to 100

// Include libraries
#include <stdio.h>

// Declare function prototype
double factorial(int); // Calculates, recursively, the factorial of a given positive integer

// Main entryway into the program
int main(void)
{
	// Loop from 1 to 100
	for(int i = 1; i <= 100; i++)
	{
		// Display the result after calling the factorial function
		printf("\n%3d! = %.0f", i, factorial(i));
	}
	
	puts(""); // Extra new-line for user readability
}

// Calculates, recursively, the factorial of a given positive integer
double factorial(int x)
{
	if(x == 0) // If x is 0, then return 1
		return 1;
	else // Otherwise, return x multiplied by the return value of factorial(x - 1)
		return x * factorial(x - 1);
}