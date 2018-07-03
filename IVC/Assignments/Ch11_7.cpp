/*
	Program: Corporate Sales (Ch11_7.cpp)
	Written by: Robby Sanchez
	This program displays a table showing the division sales for each quarter and the total corporate sales for the year.
	May 26, 2015
*/

#define _CRT_SECURE_NO_WARNINGS					// Needed for Microsoft Visual Studio
#include <iostream>								// Use for cout
#include <iomanip>								// Header file needed to use setprecision

using namespace std;

//DivSales class declaration
// class declartion
class DivSales 
{
private:
	static int yrSales;							// Holds total corporate sales fo all divisions
	int Q_Sales[4];								// Four elements for holding four quarter sales
public:
	void addSales(int,int,int,int);				// Calculates sales annually
	int sales(int);								// outputs
	int getValue()								// Returns the value in yrSales
	{
		return yrSales;
	}
};

//A function that takes an integer argument within the range of 0 to 3
void DivSales::addSales(int s1, int s2, int s3, int s4)
{
	//arrays range of 0 to 3
	Q_Sales[0] = s1;
	Q_Sales[1] = s2;
	Q_Sales[2] = s3;
	Q_Sales[3] = s4;
	//Calculates the integer arguments
	yrSales = s1 + s2 + s3 + s4;
}
//Displays a table showing the division sales for each quarter
int DivSales::sales(int n)
{
	int Value = Q_Sales[n];		//n holds value from inout to return for output
	return Value;			
}

//Definition of the static member of the DivSales class
int DivSales::yrSales;

int main()
{
	const int ds = 6;						// Six DivSales objects
	DivSales divisionSales[ds];				// Creates instances of the DivSales class
	int quarter, division;					// Holds value for quarter and division 

	// Displays the loop of the 6 divisions
	for(division = 0; division < 6; division++)
	{
		int q1, q2, q3, q4;
		cout << "Enter the sales for each division " << (division + 1) << "\n";
		cout << "Enter Quarter 1 Sales: ";
		cin >> q1;
		cout << "Enter Quarter 2 Sales: ";
		cin >> q2;
		cout << "Enter Quarter 3 Sales: ";
		cin >> q3;
		cout << "Enter Quarter 4 Sales: ";
		cin >> q4;

		divisionSales[division].addSales(q1,q2,q3,q4);
	}
		// Formatting table
	cout << "\n----------------------------------------";
	cout << "\nDivision sales for each quarter" ;
	cout << "\n----------------------------------------\n";
	cout << "\t\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;

	// Table showing the division sales for each quarter
	for(division = 0; division < 6; division++)
	{
		cout << "Division " << (division + 1) << ":";
		for(quarter = 0; quarter < 4; quarter++)
		{
			cout << "\t$" << divisionSales[division].sales(quarter);
		}
		cout << "\n";
	}
	// Displays total
	cout << "----------------------------------------\n";
	cout << "\nTotal corporate sales for the year: ";
	cout << "$" << divisionSales[0].getValue() << endl;

	system("pause"); // Needed for MS Visual Studio
}

//--------My output--------------
/*
Enter the sales for each division 1
Enter Quarter 1 Sales: 1
Enter Quarter 2 Sales: 1
Enter Quarter 3 Sales: 1
Enter Quarter 4 Sales: 1
Enter the sales for each division 2
Enter Quarter 1 Sales: 2
Enter Quarter 2 Sales: 2
Enter Quarter 3 Sales: 2
Enter Quarter 4 Sales: 2
Enter the sales for each division 3
Enter Quarter 1 Sales: 3
Enter Quarter 2 Sales: 3
Enter Quarter 3 Sales: 3
Enter Quarter 4 Sales: 3
Enter the sales for each division 4
Enter Quarter 1 Sales: 4
Enter Quarter 2 Sales: 4
Enter Quarter 3 Sales: 4
Enter Quarter 4 Sales: 4
Enter the sales for each division 5
Enter Quarter 1 Sales: 5
Enter Quarter 2 Sales: 5
Enter Quarter 3 Sales: 5
Enter Quarter 4 Sales: 5
Enter the sales for each division 6
Enter Quarter 1 Sales: 6
Enter Quarter 2 Sales: 6
Enter Quarter 3 Sales: 6
Enter Quarter 4 Sales: 6

----------------------------------------
                Q1      Q2      Q3      Q4
Division 1:     $1      $1      $1      $1
Division 2:     $2      $2      $2      $2
Division 3:     $3      $3      $3      $3
Division 4:     $4      $4      $4      $4
Division 5:     $5      $5      $5      $5
Division 6:     $6      $6      $6      $6
----------------------------------------

Total corporate sales for the year: $24
Press any key to continue . . .
*/