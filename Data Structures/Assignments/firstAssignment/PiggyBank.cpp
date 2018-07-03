#include <iostream>
#include <iomanip>			 // setprecision and fixed in print function						
#include "PiggyBank.h"		 // import the PiggyBank header file and Container header file
#include "Container.h"

using namespace std;
// PiggyBank constructor
PiggyBank::PiggyBank()
{
	//Set variables to 0
   numCents = 0;
   numNickels = 0;
   numDimes = 0;
   numQuarters = 0;
   value = 0.0;
}

//Functions adds coins
void PiggyBank::addCoins (Container& c)
{
   //statement to see if coins are < 10
   if(numCents+numNickels+numDimes+numQuarters<=10) {

       switch(c.getType())
       {
        //Accumulates which coin specified
       case(cent):
           numCents += c.getNumber();
           break;
       case(nickel):
           numNickels+= c.getNumber();
           break;
       case(dime):
           numDimes+= c.getNumber();
           break;
       case(quarter):
           numQuarters+= c.getNumber();
           break;
       default:
           break;
       }
       value += c.getValue();
   }
   else {
       cout << "Piggy bank coins exceed" << endl << endl;
   }
}

//Function removes coins
void PiggyBank::removeCoins (int amount)
{
	//Set variables to 0
   int withDrawValue = 0;  
   int centsToRemove = 0;
   int nickelsToRemove = 0;
   int dimesToRemove = 0;
   int quartersToRemove = 0;
   //Statement to see if it passed the exceeded value
   if ( (amount * 0.01) <= value)
   {
       int stillAmountRequired = amount;
       //Calculates coins together
       int totalValue= numQuarters * quarter +
                               numDimes * dime +
                               numNickels * nickel +
                               numCents * cent;
      
       //Loop to remove amount of quarters
       while (withDrawValue + quarter < amount && numQuarters - quartersToRemove > 0)
       {
           quartersToRemove++;
           withDrawValue += quarter;
       }
      //If specified coins need to be removed
       stillAmountRequired = (amount - withDrawValue);
       totalValue-= numQuarters * quarter;
      
       if( numQuarters - quartersToRemove > 0 && totalValue < stillAmountRequired )
       {
           quartersToRemove++;
           withDrawValue += quarter;
       }

       //Loop to remove amount of dimes
       while (withDrawValue + dime < amount && numDimes - dimesToRemove > 0)
       {
           dimesToRemove++;
           withDrawValue += dime;
       }
	   //If specified coins need to be removed
       stillAmountRequired = (amount - withDrawValue);
       totalValue-= numDimes * dime;

       if(numDimes - dimesToRemove > 0
           && totalValue < stillAmountRequired )
       {
           dimesToRemove++;
           withDrawValue += dime;
       }

       //Loop to remove amount of nickels
       while (withDrawValue + nickel < amount
           && numNickels - nickelsToRemove > 0)
       {
           nickelsToRemove++;
           withDrawValue += nickel;
       }
      //If specified coins need to be removed
       stillAmountRequired = (amount - withDrawValue);
       totalValue-= numNickels * nickel;

       if(numNickels - dimesToRemove > 0
           && totalValue < stillAmountRequired )
       {
           nickelsToRemove++;
           withDrawValue += nickel;
       }

       //Loop to remove amount of pennies
       while (withDrawValue + cent < amount && numCents- centsToRemove > 0)
       {
           centsToRemove++;
           withDrawValue += cent;
       }
	   //If specified coins need to be removed
       stillAmountRequired = (amount - withDrawValue);
       totalValue-= numCents * cent;

       if(numCents - centsToRemove > 0 && totalValue < stillAmountRequired )
       {
           centsToRemove++;
           withDrawValue += cent;
       }
	   //Decrements for choice of removal of coins
       value -= (withDrawValue * 0.01);
       numQuarters -= quartersToRemove;
       numDimes -= dimesToRemove;
       numNickels -= nickelsToRemove;
       numCents -= centsToRemove;
	   //Outputs for user to remove choice of coins
       cout << "Remove: " << endl << " "
           << centsToRemove << " cents, "
           << nickelsToRemove << " nickels, "
           << dimesToRemove    << " dimes, and "
           << quartersToRemove << " quarters." << endl;
       cout << " For a total of $" << setprecision(2)
           << fixed << (withDrawValue * 0.01) << endl << endl;
   }
   else
   {
       cout << "Piggy bank has insufficient funds to honor this request."
           << endl << endl;
   }
}
//Returns value
double PiggyBank::getValue()
{
   return value;
}

//Returns the value when totaled
int PiggyBank::getCount()
{
   return numCents+numNickels+numDimes+numQuarters;
}
//Outputs total
void PiggyBank::print()
{
   cout << "\n\tThe piggy bank contains: " << endl
       << "\t" << numCents << " cents\n" << "\t" << numNickels << " nickels \n"
       << "\t" << numDimes << " dimes \n" << "\t" << numQuarters << " quarters\n" << endl;

   cout << "\tThe piggy bank contains a total balance of $" << setprecision(2) << fixed << value << endl;
      
}