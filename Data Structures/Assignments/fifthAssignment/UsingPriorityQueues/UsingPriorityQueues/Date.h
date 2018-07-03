// FILE: Date.h
#ifndef DATE_H // multiple inclusion guard
#define DATE_H

#include <iostream>
#include <iomanip> //  // Provide setw() and setprecision() functions
using namespace std;

class Date
{
private:
	int m; // month
	int d; // day
	int y; // year

public:
	// default constructor:
	Date(int month = 1, int day = 1, int year = 1) : m(month), d(day), y(year) {}

	// Default unary predicate (less: max Heap):
	bool operator<(const Date& d2) const
	{
		if (y < d2.y)
			return true;
		if (y > d2.y)
			return false;
		else if (m < d2.m)
			return true;
		else if (m > d2.m)
			return false;
		else if (d < d2.d)
			return true;
		else if (d > d2.d)
			return false;
		else // equal
			return false;
	}

	// Unary predicate (greater: min Heap):
	bool operator>(const Date& d2) const
	{
		if (y > d2.y)
			return true;
		if (y < d2.y)
			return false;
		else if (m > d2.m)
			return true;
		else if (m < d2.m)
			return false;
		else if (d > d2.d)
			return true;
		else if (d < d2.d)
			return false;
		else // equal
			return false;
	}

	friend ostream & operator<<(ostream & os, Date & E); // to use with cout...
};

ostream & operator<<(ostream & os, Date & D)
{
	os << setw(3) << D.m << " " << setw(3) << D.d << " " <<
		setw(5) << D.y << endl;
	return os;
}
#endif // DATE_H


