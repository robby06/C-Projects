/*
	Program: Inventory Class (Ch7_7)
	Written by: Robby Sanchez
	This program uses an Inventory class that can hold information for an item in a retail store’s inventory.
	April 14, 2015
*/

#define _CRT_SECURE_NO_WARNINGS		// Needed for Mircosoft Visual Studio
#include <iostream>					// Use of cout
#include <iomanip>					// header file needed  to use stream manipulators

using namespace std;

class Inventory
{
	private:
		int itemNumber;				// holds the item’s number
		int quantity;				// holds the quantity of the item onhand.
		double cost;				// holds the wholesale per-unit cost of the item
	    double totalCost;			// holds the total inventory cost of the item
	public:
		//default constructor
		//Sets all the member variables to 0.
		Inventory()
		{
			itemNumber = 0;
			quantity = 0;
			cost = 0.0;
			totalCost = 0.0;
		}

		Inventory(int itemNumber, int quantity, double cost)
		{
			itemNumber = getItemNumber();
			quantity = getQuantity();
			cost = getCost();
			setTotalCost(quantity, cost);
		}

		// Accepts an int argument that is copied to the itemNumber member variable
		void setItemNumber(int iN)
		{
			itemNumber = iN;
		}
		// Accepts an int argument that is copied to the quantity member variable
		void setQuantity(int onHand)
		{
			quantity = onHand;
		}
		// Accepts a double argument that is copied to the cost member variable
		void setCost(double c)
		{
			cost = c;
		}
		// Calculates the total inventory cost for the item
		void setTotalCost(int q, double c)
		{
			totalCost = q * c;
		}
		// Returns the value in itemNumber
		int getItemNumber()
		{
			return itemNumber;
		}
		// Returns the value in quantity
		int getQuantity()
		{
			return quantity;
		}
		// Returns the value in cost
		double getCost()
		{
			return cost;
		}
		// Returns the value in totalCost
		double getTotalCost()
		{
			return totalCost;
		}
};



int main()
{
	int itemNumber;
	int quantity;
	double cost;
	double totalCost;

	cout << "Inventory tester output \n\n";
	// Allows user to enter item number
	cout << "Enter the Item Number: ";
	cin >> itemNumber;

	// Loop until user enters a positive value
	while (itemNumber < 0)
	{
		cout << "Please enter a positive value for the Item Number: ";
		cin >> itemNumber;
	}
	cout << "\nEnter item cost (per unit): ";
	cin >> cost;
	// Loop until user enters a positive value
	while (cost < 0)
	{
		cout << "Please enter a positive value for the Cost of the item: ";
		cin >> cost;
	}
	cout << "\nEnter the quantity: ";
	cin >> quantity;
	// Loop until user enters a positive value
	while (quantity < 0)
	{
		cout << "Please enter a positive value for the Quantity of the item: ";
		cin >> quantity;
	}
	// Calculates the inventory cost
	totalCost = quantity * cost;

	cout << "\nInventory Summary";
	// Set numeric values
	cout << fixed << showpoint << setprecision(2) << endl;;
	cout << "Item: " << itemNumber  << endl;
	cout << "Price per unit $" << cost << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Total cost $" << totalCost << endl;
	
	system("PAUSE");
}

//--------My Output----------
/*
Inventory tester output

Enter the Item Number: 2341

Enter item cost (per unit): 14.75

Enter the quantity: 5

Inventory Summary
Item: 2341
Price per unit $14.75
Quantity: 5
Total cost $73.75
Press any key to continue . . .
*/