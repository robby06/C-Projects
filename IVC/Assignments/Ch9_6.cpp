/*
	Program: String Selection Sort
	Written by: Robby Sanchez
	This program uses the selectionSort function to sort an array of strings
	May 5, 2015
*/

#define _CRT_SECURE_NO_WARNINGS		// Needed for Mircosoft Visual Studio
#include <iostream>					// Use of cout
#include <string>					// to use string objects
using namespace std;

// Function prototypes
void selectionSort(string array[], const int Size);
void showArray(string[], int);
int findSmallest(string array[], int startIndex, int endIndex);
void swap(string& first, string& second);
void print(string array[], const int Size); 


int main()
{
   const int SIZE = 20;
   
   string name[SIZE] = 
   {"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
    "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
    "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
    "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};
	
   	// Display the values
	cout << "The unsorted values are\n";
	showArray(name, SIZE);
	selectionSort(name, SIZE);

  	// Display the values again
	cout << "\nThe sorted values are\n";
	selectionSort(name, SIZE);
	print(name, SIZE);

	system("PAUSE");

}

// This function performs an ascending-order selection sort on array.
void selectionSort(string array[], const int Size)
{
	int smallestIndex = 0;
		for(int i = 0; i < Size; i++)
		{
			smallestIndex = findSmallest(array, i, Size - 1);
			swap(array[i], array[smallestIndex]);
		}
}

// This function displays the given set of names
void showArray(string array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}

// This function returns smallest string of the value passed into its int
int findSmallest(string array[], int startIndex, int endIndex)
{
	int smallestIndex = startIndex;
		for(int i = startIndex + 1; i <= endIndex; i++)
		{
			if(array[i] < array[smallestIndex])
				smallestIndex = i;
		}
	return smallestIndex;
}

// This function swaps the strings as it is passed by reference
void swap(string& first, string& second)
{
	string temp = first;
	first = second;
	second = temp;
}

// This function displays the strings in ascending order
void print(string array[], const int Size)
{
	for(int i = 0; i < Size; i++)
		cout << array[i] << endl;
} 
// -------------------------my output-------------------------------------------
/*
The unsorted values are
Collins, Bill Smith, Bart Michalski, Joe Griffin, Jim Sanchez, Manny Rubin, Sara
h Taylor, Tyrone Johnson, Jill Allison, Jeff Moreno, Juan Wolfe, Bill Whitman, J
ean Moretti, Bella Wu, Hong Patel, Renee Harrison, Rose Smith, Cathy Conroy, Pat
 Kelly, Sean Holland, Beth

The sorted values are
Allison, Jeff
Collins, Bill
Conroy, Pat
Griffin, Jim
Harrison, Rose
Holland, Beth
Johnson, Jill
Kelly, Sean
Michalski, Joe
Moreno, Juan
Moretti, Bella
Patel, Renee
Rubin, Sarah
Sanchez, Manny
Smith, Bart
Smith, Cathy
Taylor, Tyrone
Whitman, Jean
Wolfe, Bill
Wu, Hong

Press any key to continue . . .
*/