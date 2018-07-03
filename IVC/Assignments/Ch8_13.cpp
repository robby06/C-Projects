/*
	Program: Array of Payroll Objects (ch8_13.cpp)
	Written by: Robby Sanchez
	This program reads the raw data of hours and payrate.
	May 5, 2015
*/
#define _CRT_SECURE_NO_WARNINGS			// Needed fir Microsoft Visual Studio
#include <iostream>						// Use if cout
#include <iomanip>						// header file needed to use setprecision
#include <fstream>						// Needed to use files
using namespace std;

class Payroll
{
	private:
		double payRate;     // holds an employee hourly pay rate
		double hoursWorked;  // an employee's hours worked

	public:
		Payroll();								// empty constructor sets the payRate and hoursWorked to zero
		Payroll(double payR, double hoursW);	//constructor checks for payR and hoursW to be positive
												// and sets payRate and hours worked; sets to zero if negative values are provided
		void setPayRate(double payR);			//mutator for payRate; checks for payR to be positive or sets to zero
		void setHoursWorked(double hoursW);		//mutator for hoursWorked; checks for positive hoursW or sets to zero
		double getPayRate();					//accessor to return payRate
		double getHoursWorked();				// accessor to return hoursWorked
		double getGrossPay();					// computes and returns gross pay including OVERTIME as 1.5 * payRate * (hoursWorked - 40), if any
};

int main ()
{
	const int employees = 7;				// Number of employees, [Professor, please set to 10 to test and calculate overtime]
	int hours[employees];					// Define 2 parallel arrays
	double payrate[employees];
	int count;								// Loop counter

	 // Used to read data from a file
	ifstream datafile;

		// Open the input file
		datafile.open("payroll.dat");

		if (!datafile)
			cout << "Error opening data file \n";
				else
				{
					// Loop to calculate payroll data
					for (count = 0; count < employees; count++)
					{
						double hours;
						double payrate;
						double grosspay;

						datafile >> hours;
						datafile >> payrate;
						if(hours <=40)
							 grosspay = hours * payrate;		
						else if
							(hours > 40)
							 grosspay = (1.5 * hours * payrate);		// my overtime calculations

			// Display each employee's gross pay
				cout << "\n" << fixed << setprecision (2);
				cout << "Employee#" << setw (2) << (count+1) << "~ Your gross pay is: $" 		
					 << grosspay << endl;			
			}
		}	
		datafile.close();	// Close the file
		system("Pause");	// Needed for MS Visual Studio
	}		
	






















