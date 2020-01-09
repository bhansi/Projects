// Name: Baljot Hansi, Date: November 25, 2018, Section: 55

// Perfect Number Calculator program

// Include libraries
#include <stdio.h>

// Declare function prototype
int isPerfect(int); // Checks if a given integer is a perfect number

// Main entryway into the program
int main(void)
{
	// Run a loop from 1 to 1000
	for(int i = 1; i <= 1000; i++)
	{
		if(isPerfect(i) == 1) // Call isPerfect function. If i is a perfect number, then:
		{
			printf("\n%d = ", i); // Print the start of the complete printout for displaying the perfect number
			
			// Loop from i to 1 to check for the factors that don't leave remainders when divided i (the perfect number) and div
			for(int div = i - 1; div > 0; div--)
			{
				if(div > 1 && i % div == 0) // If i divided by div doesn't leave a remainder, then:
				{
					printf("%d + ", div); // Printout the middle of the complete printout for displaying the perfect number
				}
				else if(div == 1)
					printf("%d\n", div); // Print the end of the complete printout for diplaying the perfect number
			}
		}
	}
}

// Checks if a given integer is a perfect number
int isPerfect(int num)
{
	// Define a local variable to hold the sume
	int sum = 0;
	
	// Run a loop from num - 1 to 1
	for(int i = num - 1; i > 0; i--)
	{
		// If num divided by i doesn't leave a remainder, then add it to sum
		if(num % i == 0)
			sum += i;
	}
	
	if(sum == num) // If the sum of non-remainder producing divisors is the same as num, then num is a perfect number and return 1
		return 1;
	else // Otherwise, num is not a perfect number and return 0
		return 0;
}