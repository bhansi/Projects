// Name: Baljot Hansi, Date: November 25, 2018, Section: 55

// Multiplication Practice program

// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main entryway into the program
int main(void)
{
	// Have a different seed for the rand function so that the the numbers pulled from rand are different each time
	srand(time(NULL));
	
	// Define local variables: x to hold the first number, y to hold the second number, ans to hold the answer of x * y, try to hold the user's input on what x * y is
	int x, y, ans, try;
	
	// Loop infinitely
	while(1)
	{
		// Calculate x, y, and ans
		x = 1 + rand() % 9;
		y = 1 + rand() % 9;
		ans = x * y;

		// Get the value for try from the user
		printf("\nHow much is %d times %d?\n", x, y);
		scanf("%d", &try);
		
		if(try < 0) // If the user enters a negative number, break from the infinite loop
			break;
		
		// Loop until the user enters the correct answer for x * y
		while(ans != try)
		{
			// Continuously get tries from the user to compare to ans
			printf("%s", "\nNo. Please try again.\n");
			scanf("%d", &try);
		}
		
		printf("%s", "Very good!\n"); // Display a contgratulatory message upon a correct answer 
	} // The loop continues
} // The program ends