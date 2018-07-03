/*
	-Program: Lowest Score Drop (Ch6_7)
	-Written by: Robby Sanchez
	-This program calculates the average of a group of test scores, where the lowest score in the group is dropped
	-April 14, 2015
*/

#define _CRT_SECURE_NO_WARNINGS			// Needed for Mircosoft Visual Studio
#include <iostream>						// Use of cout
#include <iomanip>						// header file needed to use setprecision

using namespace std;

// Function prototype
void getScore(int &);								// Uses reference parameters to input values in the function
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);
         
int main()
{
			// Declaring test scores
         int testScr1, testScr2, testScr3, testScr4, testScr5;
         
		 // Call getScore to get a number and store it in value
         getScore(testScr1);
         getScore(testScr2);
         getScore(testScr3);
         getScore(testScr4);
         getScore(testScr5);
  
         calcAverage(testScr1, testScr2, testScr3, testScr4, testScr5);
  
			system("PAUSE"); // Needed for MS Studio
}
  
                               
/*	- Function allows user to enter test score
	- Arguments passed into score are passed by reference so that
		values entered into them will actually be stored in the memory space of main testscore 1-5.
*/	
void getScore(int &score)
{
         cout << "Enter a test score: ";
         cin >> score;
         
		 // Loop until user enters 5 test scores
         while (score < 0 || score > 100)
         {
                  cout << "Please enter a valid test score that between 0 to 100: ";
                  cin >> score;
         }
  
}
  
  
// Function calculates average and drops lowest test score
void calcAverage(int s1, int s2, int s3, int s4, int s5)
{
         int sum;			// sum of test scores
         int lowest;		// lowest test score
         double average;	// average test scores with lowest dropped
         
		 // Identifies lowest test score
         lowest = findLowest(s1, s2, s3, s4, s5);
		
		 // Calculates sum & average of test scores with lowest score dropped
         sum = s1 + s2 + s3 + s4 + s5 - lowest;
         average = sum/4.0;
         
         cout << setw(4) << fixed << showpoint << setprecision(0);		// Set numeric output formatting
         cout << "The average of the four highest scores are: " 
			 << average << endl;
}
  
  
// Function returns the lowest test score
int findLowest(int s1, int s2, int s3, int s4, int s5)
{
         int lowest = s1; 
         
     // using if statement to locate lowest test score   
	if(s2 < lowest )       
	{
         lowest = s2;
	}
	if(s3 < lowest)
	{
         lowest = s3;
	}
	if(s4 < lowest)
	{
		lowest = s4;
	}
	if(s5 < lowest)
	{
		lowest = s5;
	}

         cout << "\nThe lowest test score is: " << lowest << endl;
  
    return lowest;
}


//---------My Output------------------
/*
Enter a test score: 90
Enter a test score: 85
Enter a test score: 80
Enter a test score: 85
Enter a test score: 100

The lowest test score is: 80
The average of the four highest scores are: 90.
Press any key to continue . . .
*/


























