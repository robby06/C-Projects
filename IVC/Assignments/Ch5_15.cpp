/*
	Program: Population (Ch5_15.cpp)
	Written by: Robby Sanchez
	This program predict the size of a population of organisms
	March 12, 2015
*/

#define _CRT_SECURE_NO_WARNINGS // needed for MS studio
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float snoo = 0.0; //Starting number of organisms
	float di = 0.0; // Daily percentage as it increases
	int dm = 0; // Multiply by number of days

	cout << "Enter the starting number of organisms: ";
	cin >> snoo;

			//validates the starting number of organisms
		while(snoo < 2) 
		{
			cout << "The starting number of organisms must be at least 2. \n";
			cout << "Enter the starting number of organisms: ";
			cin >> snoo;
		}

	cout << "\nEnter the average daily population increase (as a percentage): ";
	cin >> di;

			// validates average daily population increase
		while(di < 0) 
		{
			cout << "The average daily population increase must be a positive value. \n";
			cout << "Enter the average daily population increase (as a percentage): ";
			cin >> di;
		}

	cout << "\nEnter the number of days they will multiply: ";
	cin >> dm;
  
			// validates the number of days they will multiply
		while(dm < 1) 
		{
			cout << "The number of days must be at least 1. \n";
			cout << "Enter the number of days they will multiply: ";
			cin >> dm; 
		}
	  
			//displays size of population for each day
		for (int count = 0; count != dm; count++) 
		{
			cout << "\nOn day " << count + 1 << " the population size was " << snoo << "." << endl;
			snoo = snoo + (snoo * di/100);
	  
		}
	system("PAUSE");
}

//My output
/*
Enter the starting number of organisms: 1
The starting number of organisms must be at least 2.
Enter the starting number of organisms: 2

Enter the average daily population increase (as a percentage): -5
The average daily population increase must be a positive value.
Enter the average daily population increase (as a percentage): 5

Enter the number of days they will multiply: 0
The number of days must be at least 1.
Enter the number of days they will multiply: 5

On day 1 the population size was 2.

On day 2 the population size was 2.1.

On day 3 the population size was 2.205.

On day 4 the population size was 2.31525.

On day 5 the population size was 2.43101.
Press any key to continue . . .
*/