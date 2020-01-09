// Name: Baljot Hansi, Std#: 105160856, Date: Oct 23, 2018, Lab Section: 55
#include <stdio.h> // Include standard io libraries
#include <stdlib.h>

// Declare function prototypes
int size(char *r); // Sets size of valid characters in the expression
int check(char *r, int lim); // Checks the type of expression being evaluated and calls functions accordingly
int simpleAandS(char *r, int lim); // Does simple left to right evaluation for addition and subtraction
int simpleMandD(char *r, int lim); // Does simple left to right evaluation for multiplication and division
int exponent(int base, int power); // Does simple power evaluation
void middleEval(char *r, int opPos, int lim); // Evaluate multiplication/division first in a complex expression
void replace(char *r, int leftPH, int rightPH, int eval); // Replace the evaluated portion with non-readable characters

// Declare global variable
int divBZ = 0; // Checks for division by 0

// Entryway to program through main function
int main(void)
{
	// Define variable to hold entered expression
	char expr[256];
	
	// Display printouts to the user
	printf("\n%s\n", "Valid characters for this calculator are: + , - , * , / , ^ , and all positive integer numbers.");
	printf("%s\n", "To escape the calculator, press 'ctrl+c'.");
	
	// Loop until the user exits the program with ctrl+c
	while(1)
	{
		// Retrieve expression from user 
		printf("\nEnter an expression: ");
		gets(expr);

		// Calculate the result
		int result = check(expr, size(expr));
		
		if(divBZ == 0) // No division by zero detected
			printf("\nThe expression evaluates to: %d\n\n", result);
			
		else // Division by zero detected
		{
			printf("%s", "Division by zero!\n");
			divBZ = 0;
		}
	}
}

// Checks the size of the expression (how many characters are valid)
int size(char *r)
{
	int sz = 0;
	for(int i = 0; i < 256; i++)
	{
		// the expression is valid until a character is not an integer or is not one of the characters listed in the beginning print out
		if(r[i] != '0' && r[i] != '1' && r[i] != '2' && r[i] != '3' && r[i] != '4' && r[i] != '5' && r[i] != '6' && r[i] != '7' && r[i] != '8' && r[i] != '9' && r[i] != '+' && r[i] != '-' && r[i] != '*' && r[i] != '/' && r[i] != '^')
		{
			sz = i;
			break;
		}
	}
	return sz;
}

// Checks the type of expression entered (simple addition/subtraction or simple multiplication/division or complex expression)
int check(char *r, int lim)
{
	for(int i = 0; i < lim; i++) // Loop through all valid characters
	{
		if(r[i] == '+' || r[i] == '-') // Check for addition and subtraction
		{
			for(int j = i; j < lim; j++) // Run loop to check for complex expression
			{
				if(r[j] == '*' || r[j] == '/') // Expression is complex
				{
					middleEval(r, j, lim);
				}
			}
			return simpleAandS(r, lim); // Expression is simple addition and subtraction
		}
		
		else if(r[i] == '*' || r[i] == '/') // Check for multiplication and division
		{
			for(int j = i; j < lim; j++) // Run loop to check for complex expression
			{
				if(r[j] == '+' || r[j] == '-') // Expression is complex
				{
					middleEval(r, i, lim);
					return check(r, lim);
				}
			}
			return simpleMandD(r, lim); // Expression is simple multiplication and division
		}
		
		else if(r[i] == '^') // Expression is using order
		{
			int base = atoi(r), power = atoi(r + i + 1); // Calculate the base and the exponent
			return exponent(base, power);
		}
	}
	return simpleAandS(r, lim); // Final return value to cover all program paths
}

// Does simple left to right evaluation for addition and subtraction
int simpleAandS(char *r, int lim)
{
	// Define local variables
	int total = atoi(r), num; // Set the first number in the array to total
	
	// Loop through the rest of the array and continually add and subtract until the size of the expression is reached
	for(int i = 0; i < lim; i++)
	{
		if(r[i] == '+')
		{
			num = atoi(r + i + 1);
			total += num;
		}
		else if(r[i] == '-')
		{
			num = atoi(r + i + 1);
			total -= num;
		}
	}
	return total;
}

// Does simple left to right evaluation for multiplication and division
int simpleMandD(char *r, int lim)
{
	// Define local variables
	int total = atoi(r), num; // Set the first number in the array to total
	
	// Loop through the rest of the array and continually mutiply and divide until the size of the expression is reached
	for(int i = 0; i < lim; i++)
	{
		if(r[i] == '*')
		{
			num = atoi(r + i + 1);
			total *= num;
		}
		
		else if(r[i] == '/')
		{
			num = atoi(r + i + 1);
			if(num == 0) // Check if division by zero is being excecuted
			{
				divBZ = 1;
				break;
			}
			
			else
				total /= num;
		}
	}
	return total;
}

// Does simple power evaluation
int exponent(int base, int power)
{
	if(power == 0) // The exponent is 0 and the expression evaluates to 1
		return 1;
	
	else if(power == 1)
		return base;
	
	else
		return base * exponent(base, power - 1);
}

// Evaluate multiplication/division first in a complex expression
void middleEval(char *r, int opPos, int lim)
{
	// Define local variables
	int eval, num1, num2, rightPH;
	
	for(int leftPH = opPos - 1; leftPH >= 0; leftPH--) // Loop from the operator position to the beginning of the array
	{
		if(r[leftPH] == '+' || r[leftPH] == '-') // If another operater is found
		{
			if(r[opPos] == '*')
			{
				num1 = atoi(r + leftPH + 1); // num1 = the number to the right of the found operator
				num2 = atoi(r + opPos + 1); // num2 = the number to the right of the multiplication operator
				eval = num1 * num2;
				
				// Loop from opPos to the next operator (or the end of the array) to check how many characters must be replaced
				for(int j = opPos + 1; j < lim; j++)
				{
					if(r[j] == '+' || r[j] == '-' || r[j] == '*' || r[j] == '/') // Operator is found and is the right limit
					{
						rightPH = j - 1;
						break;
					}
					
					else if(j == lim - 1) // The end of the array is the right limit
						rightPH = j;
				}
				replace(r, leftPH + 1, rightPH, eval); // Call the replace function to replace the mid-evaluated expression with the evaluated value
				break;
			}
			else if(r[opPos] == '/')
			{
				num1 = atoi(r + leftPH + 1); // num1 = the number to the right of the found operator
				num2 = atoi(r + opPos + 1); // num2 = the number to the right of the division operator
				
				if(num2 == 0) // Check for division by zero
				{
					divBZ = 1;
					break;
				}
				
				eval = num1 / num2;
				
				// Loop from opPos to the next operator (or the end of the array) to check how many characters must be replaced
				for(int j = opPos + 1; j < lim; j++)
				{
					if(r[j] == '+' || r[j] == '-' || r[j] == '*' || r[j] == '/') // Operator is found and is the right limit
					{
						rightPH = j - 1;
						break;
					}
					
					else if(j == lim - 1) // The end of the array is the right limit
						rightPH = j;
				}
				replace(r, leftPH + 1, rightPH, eval); // Call the replace function to replace the mid-evaluated expression with the evaluated value
				break;
			}
		}
		else if(leftPH == 0 && r[opPos] == '*') // If it is not found, evaluate for multiplication
		{
			num1 = atoi(r); // num1 = the first number in the expression
			num2 = atoi(r + opPos + 1); // num2 = the number to the right of the multiplication operator
			
			eval = num1 * num2;
			
			// Loop from opPos to the next operator (or the end of the array) to check how many characters must be replaced
			for(int j = opPos + 1; j < lim; j++)
			{
				if(r[j] == '+' || r[j] == '-' || r[j] == '*' || r[j] == '/') // Operator is found and is the right limit
				{
					rightPH = j - 1;
					break;
				}
				
				else if(j == lim - 1) // The end of the array is the right limit
					rightPH = j;
			}
			replace(r, leftPH, rightPH, eval); // Call the replace function to replace the mid-evaluated expression with the evaluated value
			break;
		}
		else if(leftPH == 0 && r[opPos] == '/') // If it is not found, evaluate for division
		{
			num1 = atoi(r); // num1 = the first number in the expression
			num2 = atoi(r + opPos + 1); // num2 = the number to the right of the division operator
			
			if(num2 == 0) // Check for division by zero
			{
				divBZ = 1;
				break;
			}
			
			eval = num1 / num2;
			
			// Loop from opPos to the next operator (or the end of the array) to check how many characters must be replaced
			for(int j = opPos + 1; j < lim; j++)
			{
				if(r[j] == '+' || r[j] == '-' || r[j] == '*' || r[j] == '/') // Operator is found and is the right limit
				{
					rightPH = j - 1;
					break;
				}
				
				else if(j == lim - 1) // The end of the array is the right limit
					rightPH = j;
			}
			replace(r, leftPH, rightPH, eval); // Call the replace function to replace the mid-evaluated expression with the evaluated value
			break;
		}
	}
}

// Replace the evaluated portion with the evaluation and non-readable characters
void replace(char *r, int leftPH, int rightPH, int eval)
{
	// Define variables
	char snum[256];
	int snumSZ;
	
	// Set a char array equal to the evaluated number
	sprintf(snum, "%d", eval);
	snumSZ = size(snum);
	
	// For non-readable characters
	for(int i = leftPH; i <= rightPH; i++)
	{
		r[i] = ':';
	}
	
	// For evaluation
	for(int i = 0; i < snumSZ; i++)
	{
		r[leftPH + i] = snum[i];
	}
}