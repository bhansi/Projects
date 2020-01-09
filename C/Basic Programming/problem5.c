// Name: Baljot Hansi, Date: November 25, 2018, Section: 55

// Palindrome Check program

// Include libraries
#include <stdio.h>
#include <ctype.h>

// Declare function prototype
_Bool testPalindrome(char*, int, int); // Tests whether a given string of characters is a palindrome or not

// Main entryway into the program
int main(void)
{
	// Define local variables
	char strg[256]; // Holds a string of 256 (arbitrary large number) characters
	int size; // Holds the number of characters in the string

	// Get a string from the user
	printf("%s", "\nEnter a sentence: ");
	gets(strg);
	
	// The block of code below manipulates the string by eliminiating characters that are not alphanumeric and changing all characters to lowercase
	
	// Run through each valid character in the string
	for(size = 0; strg[size]; size++)
	{
		if(isalnum(strg[size]) == 0) // If a character is not alphanumeric, then:
		{
			// Run a loop from that character to the end of the string
			for(int j = size; strg[j]; j++)
				strg[j] = strg[j + 1]; // Shift the characters one space to the left, thus eliminating the non-alphanumeric character
			
			size--; // Shift the place of the array back by one in order to make sure that all non-alphanumeric characters are eliminated in subsequent iterations
		}
		
		// Convert a character to lowercase
		strg[size] = tolower(strg[size]);
	}
	
	// Based on the return value of the testPalindrome function (0 or 1), display to the user if the string they entered is a palindrome or not
	if(testPalindrome(strg, 0, size - 1))
		printf("%s", "\nThis sentnce is a palindrome.\n");
	else
		printf("%s", "\nThis sentnce is not a palindrome.\n");
} // The program ends

// Tests whether a given string of characters is a palindrome or not; left and right are the placeholders on either side of the string to test if the characters are identical
_Bool testPalindrome(char *r, int left, int right)
{
	if(left == right || (right - left == 1 && r[left] == r[right])) // If the middle of the string has been reached OR the middle has been reached for an even number of characters in the string and the characters to the immediate left and right of the middle are identical, then return 1
		return 1;
	
	else if(r[left] != r[right]) // Otherwise, if the two characters are not identical, return 0
		return 0;
		
	else // Otherwise, return 1 * the return value of testPalindrom, where the funciton is called with a incremented left value and a decremented right value; if at any point, the return value is 0, the entire return value becomes 0
		return 1 * testPalindrome(r, left + 1, right - 1);
}