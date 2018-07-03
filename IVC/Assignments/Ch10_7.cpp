/*
	Program: Movie Statistics Ch10_7.cpp)
	Written by: Robby Sanchez
	This program calculate the average, median, and mode of the values entered
	May 26, 2015
*/

#define _CRT_SECURE_NO_WARNINGS				// Needed for Microsoft Visual Studio
#include <iostream>							// Use for cout
#include <iomanip>							// Header file needed to use setprecision

using namespace std;

// Function prototypes
double mean(int *, int);
double median(int *, int);
int mode(int *, int);

int main()
{
	
	int *nums;			// To dynamically allocate an array
	int nStud;			// Holds the number of students
	char repeat = ' ';	// Tells user to retry after input

	do
	{
	// Prompt the user to enter in how many students were surveyed
	cout << "Enter number of students that were surveyed: ";
	cin >> nStud;

	// Determine input validation
	while (nStud < 0)
	{
		cout << "Invalid number of students!\n";
		cout << "Enter in how many students were surveyed: ";
		cin >> nStud;
	}

	// Dynamically allocate an array large enough to hold a certain numbers of students
	nums = new int[nStud];

	// Get the number of movies for each student;
	for (int count = 0; count < nStud; count++)
	{
		cout << "Number of movies say by Person #" << (count + 1) << ": ";
		cin >> nums[count];

		// Determine input validation
		while (nums[count] < 0)
		{
			cout << "Please enter in a positive number: ";
			cout << "\nNumber of movies say by Person #" << (count + 1) << ": ";
			cin >> nums[count];
		}

	}

	// Set numeric values
	cout << fixed << showpoint << setprecision(1);
	
	// Display the mean
	cout << "\nThe mean is: ";
	cout << mean(nums, nStud) << endl;

	// Display the median
	cout << "\nThe median is: ";
	cout << median(nums, nStud) << endl;

	// Display the mode
	cout << "\nThe mode is: ";
	cout << mode(nums, nStud) << endl;
	
	// Free dynamically allocated memory
	delete[] nums;
	nums = 0;		

	// Ask the user to retry program or disregard 
	cout << "Do you want to go again? ";
	cin >> repeat;

	
	} while (repeat == 'Y' || repeat == 'y');
	cout << "Program ending.\n";
	
	system("pause"); //Needed for MS Visual Studio
}


// Function returns the value of mean(average)
double mean(int *nums, int nStud)
{
	double total = 0;		// Accumulator
	double average;			// Holds value for average

	// Calculates average
	for (int count = 0; count < nStud; count++)
	{
		total += nums[count];
	}
	average = total / nStud;
	return average;
}

// Function returns the value of median
double median(int *nums,  int nStud)
{
	double median = 0.0;	// Holds value for median	
	
	// Formula to calculate median
	if (nStud % 2 == 0)
	{
		median = (nums[nStud / 2] + nums[(nStud / 2) + 1]) / 2;
	}
	else
		median = nums[nStud / 2];

	return median;
}

//Function returns the value of mode
int mode(int *nums, int nStud)
{
	int mode = 0;				// Holds value of mode
	int val = 0;				// Holds value of value
	int index;					// Loop counter
	
	for (index = 0; index < nStud; index++)
	{
		// Formula to calculate mode
		if (*(nums + index) == *(nums + (index + 1)))
		{
			mode++;
			val = *(nums + index);
		}
	}
			return val;
}


// -----------My output------------------
/*
Enter number of students that were surveyed: 9
Number of movies say by Person #1: 50
Number of movies say by Person #2: 90
Number of movies say by Person #3: 90
Number of movies say by Person #4: 91
Number of movies say by Person #5: 50
Number of movies say by Person #6: 40
Number of movies say by Person #7: 8
Number of movies say by Person #8: 1
Number of movies say by Person #9: 4

The mean is: 47.1

The median is: 50.0

The mode is: 90
Do you want to go again?
*/



    
