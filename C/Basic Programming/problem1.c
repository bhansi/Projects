// Name: Baljot Hansi, Date: November 25, 2018, Section: 55

// Even Digit Count program

// Include standard libraries
#include <stdio.h>
#include <math.h>

// Declare function prototype
int countEvenDigits(int); // Counts the number of even digits in a given positive integer

// Main entryway into the program
int main(void)
{
	// Define local long int x variable to accurately decide whether 10 digits is entered by the user or not
	int x;
	
	// Loop 10 times
	for(int i = 0; i < 10; i++)
	{
		// Run a loop until the user enters a positive integer number
		while(1)
		{
			// Get an integer number from the user
			printf("%s", "\nPlease enter a positive integer number: ");
			scanf("%d", &x);
			
			// If the number isn't positive, inform the user and continue the loop; otherwise, break the loop
			if(x < 1)
				puts("Invalid Input.");
			else
				break;
		}
		
		// Call the countEvenDigits function and display the result to the user
		printf("\nThe number of even digits in %d is %d\n\n", x, countEvenDigits(x));
	} // The loop continues
} // The program ends

// Counts the number of even digits in a given integer
int countEvenDigits(int num)
{	
	// Define local variables: size is the number of digits in num, evenCount holds a count of the number of number of even digits, digit holds the individual digits for comparrison
	int size = log10(num * 10), evenCount = 0, digit;
	
	// Loop from 0 to one less than size
	for(int i = 0; i < size; i++)
	{
		// Separate an individual digit from num for comparrison
		digit = (num % (int) pow(10, i + 1)) / pow(10, i);
		
		if(digit % 2 == 0) // If the digit is an even number, add one to evenCount
			evenCount++;
	}
	
	return evenCount; // Return the number of even digits to the function call
}