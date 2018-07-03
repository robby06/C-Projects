/*
	Program: Password Verifier (Ch12_10.cpp)
	Written by: Robby Sanchez
	This program asks user for a password and then verifies that it meets the stated criteria
	May 26, 2015
*/

#define _CRT_SECURE_NO_WARNINGS			// Needed for Microsoft Visual Studio
#include <iostream>						// Use for cout
#include <cctype>						// Needed to use character testing function
#include <string>						// Use for string objects
using namespace std;

int main()
{

	string aPassword;					// Declares string name for aPassword

	bool goodPassword = false;
	while (goodPassword == false)
	{
		// Allows user to enter preference of a password
		cout << "Enter a password: ";
		cin >> aPassword;
		goodPassword = true;

		// Verifies if password length is at least 6 characters
		if (aPassword.length() < 6) {
			goodPassword = false;
			cout << "\nYour password is too short; must be 6+ characters\n";
			continue;
		}

		//Use for loop and switch statementy to verify if it contains at least 1 digit
		goodPassword = false;
		for (int i=0; i<aPassword.length(); ++i)
		{
			switch (aPassword[i]) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				goodPassword = true;
				break;
			}
		}

		// Error message displays if no number is entered by user
		if (goodPassword == false)
		{
			cout << "\nYour password must contain at least 1 digit\n";
			continue;
		}
	}

	// If password meets all requirements
	cout << "Your password is: " << aPassword << "\n\n";

  system("pause"); // Needed for MS Visual Studio
}

// ---------------my output------------
/*
Enter a password: Robbys1
Your password is: Robbys1

Press any key to continue . . .
*/