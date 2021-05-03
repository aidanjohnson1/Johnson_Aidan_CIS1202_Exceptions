//Aidan Johnson
//CIS 1201 101
//May 2, 2021
#include <iostream>
#include <string>
#include <ctype.h>
#include <exception>
using namespace std;

//Prototypes
char character(char, int);

int main()
{
	//Declare variables
	char startChar;
	int offsetInt;

	//Obtain values from user
	cout << "What character is your starting position?\n";
	cin >> startChar;

	cout << "How much do you want to offset this character?\n";
	cin >> offsetInt;

	//Call in function to either throw exceptions or validate, and then return the offset character
	cout << character(startChar, offsetInt);

	return 0;
}

char character(char start, int offset)
{
	try {
		if (!isalpha(start)) { //If character is a letter, go on; otherwise, throw start exception
			throw start;
		}

		try {
			if (!isalpha(start + offset)) { //If target letter is "below" the letter a, throw offset exception; otherwise, go on
				throw offset;
			}

			if (isupper(start) != isupper(start + offset)) { //Ensure that the start and target characters are of the same case; otherwise, return offset exception
				throw offset;
			}

			return start + offset; //Return the target letter
		}
		catch (int targetException) {
			cout << "invalidRangeException, Offset: " << targetException << " is not within the range.\n";
			return NULL;
		}
	} catch (char letterException) {
		cout << "invalidCharacterException, Character: " << letterException << " is not a valid letter.\n";
		return NULL;
	}
}