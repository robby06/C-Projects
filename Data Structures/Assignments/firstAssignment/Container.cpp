#include <iostream>
#include <string>			//Use for string objects
#include <iomanip>
#include "Container.h"

using namespace std;

//Global constant initialzed to corresponding value
const double Cents::VALUE       = 0.01;
const double Nickels::VALUE     = 0.05;
const double Dimes::VALUE       = 0.10;
const double Quarters::VALUE    = 0.25;

//Container constructor; sets datatype parameters to 0
Container::Container(int number = 0, int type = 0)
{
   Container::number = number;
   Container::type = type;
   //Calculates specified coins depending on user input
   switch (type)
   {
   case cent:
       value = Cents::VALUE * number;
       break;
   case nickel:
       value = Nickels::VALUE * number;
       break;
   case dime:
       value = Dimes::VALUE * number;
       break;
   case quarter:
       value = Quarters::VALUE * number;
       break;
   default:
       break;
   }
}


//Container Constructor
// Construcors that have nothing in bodies
Cents::Cents(int number):Container(number, cent)   
	{

	};

Nickels::Nickels(int number):Container(number, nickel)
	{

	};

Dimes::Dimes(int number):Container(number, dime) 
	{

	};

Quarters::Quarters(int number):Container(number, quarter)
	{

	};

//Returnss value in getNumber
int Container::getNumber()
{
   return number;
}

//Returns value in getType
int Container::getType()
{
   return type;
}

//Returns value in getValue
double Container::getValue()
{
   return value;
}


//Function that outputs coins
void Container::print()
{
   string coinTypeName = "";
   //Displays amount of coins due to user input
   switch(type)
   {
   case cent:
       coinTypeName = " cents";
       break;
   case nickel:
       coinTypeName = " nickels";
       break;
   case dime:
       coinTypeName = " dimes";
       break;
   case quarter:
       coinTypeName = " quarters";
       break;
   default:
       break;
   }
   cout << setprecision(2) << fixed << number << coinTypeName
        << " ($" << value << ") " <<endl;
}


