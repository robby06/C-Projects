/*
	* Program: Using Files-Total and Average Rainfall (Ch5_24.cpp)
	* Written by: Robby Sanchez
	* This program uses a loop to read in values from a file until the end of file is reached.
	* March 15, 2015
*/

#define _CRT_SECURE_NO_WARNINGS		// Needed for Mircosoft Visual Studio
#include <iostream>					// Use of cout
#include <iomanip>					// header file needed  to use stream manipulators
#include <fstream>					// Needed to use files
#include <string>					// To use string objects

using namespace std;

 int main()
 {
	ifstream theFile;								// File stream object
	string beg_month, end_month;					// Reads first & last month name
	float rfa1, rfa2, rfa3, rfa4, total, avg;		// Rainfall amount

	    // Open the input file
    theFile.open("Rainfall.txt"); // insert Rainfall.txt under source file name (Right below the debug file)

		// Loop for the rain amounts until EOF is reached
	while(theFile >> beg_month >> end_month >> rfa1 >> rfa2 >> rfa3 >> rfa4){
		total = rfa1 + rfa2 + rfa3 +rfa4;
		avg = (total) / 4;
		cout << "During the months of " << beg_month << "-" << end_month << " the total rainfall was " << total << fixed << setprecision(2)
			<< " inches and the \n average monthly rainfall was " << avg << fixed << setprecision(2) << " inches." << endl;
	}

	system("PAUSE"); 
 }
 // My output
 /*
 During the months of June-September the total rainfall was 6.94 inches and the
 average monthly rainfall was 1.73 inches.
Press any key to continue . . .
*/
