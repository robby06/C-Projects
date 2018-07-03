/*
	Written by Robby Sanchez
	Exercise 1: Piggy Bank using the Container Class
*/

#define _CRT_SECURE_NO_WARNINGS		//Needed for MS Studio
#include <iostream>					//Use for cout
//#include <cstdlib>
#include "PiggyBank.h"
#include "Container.h"

using namespace std;
const int Max=10;		//Global constant hold max 10 coins

int main()
{
   PiggyBank piggy;
   Cents cent[Max];				//Max of coins for pennies
   Nickels nick[Max];			//Max of coins for nickels
   Dimes dime[Max];				//Max of coins for dimes
   Quarters quart[Max];			////Max of coins for quarters
   int choice, c, n, d, q;		//hold int for user choice of coins
   double amount;				//removes amount of coins user enters
   int w=0, x=0, y=0, z=0;		//accumulator initialzed to zero

   //Do-while loop until user enters choice 4
   do
   {
       cout << "****************** PIGGY BANK MAIN MENU ******************\n";
       cout << "\t1.Show piggy bank contents and total balance.\n";
       cout << "\t2.Deposit coins in the piggy bank \n";
       cout << "\t3.Withdraw coins from the piggy bank \n";
       cout << "\t4.Exit the program\n";
       cout << "************************************************************\n";
       cout << "What would you like to do? Select a number (1-4), then press Enter: ";
       cin >> choice;

	   //Switch statement for user input
       switch(choice)
       {
       case 1:
           piggy.print();
           break;
       case 2:
           cout <<"\nYou have decided to save money (good idea!). Please Enter \n"
				"the number of coins to deposit as integers greater than or equal to zero\n";
           cout << "\nHow many cents would you like to deposit? ";
           cin >> c;
		   //proceeds if user enters < 10
           if((piggy.getCount()+c)<=10)
           {
               cent[w]=c;
               piggy.addCoins(cent[w]);
               w++;
           }
           else
           {
               cout<<"Piggy Bank is full \n";
               break;
           }
              
           cout << "How many nickels would you like to deposit? ";
           cin >> n;
           if((piggy.getCount()+n)<=10)
           {
               nick[x]=n;
               piggy.addCoins(nick[x]);
               x++;
           }
           else
           {
               cout<<"Piggy Bank is full \n";
               break;
           }
          
           cout << "How many dimes would you like to deposit? ";
           cin >> d;
           if((piggy.getCount()+d)<=10)
           {
               dime[y]=d;
               piggy.addCoins(dime[y]);
               y++;
           }
           else
           {
               cout<<"Piggy Bank is full \n";
               break;
           }
          
           cout << "How many quarters would you like to deposit? ";
           cin >> q;
           if((piggy.getCount()+q)<=10)
           {
               quart[z]=q;
               piggy.addCoins(quart[z]);
               z++;
           }
           else
           {
               cout<<"Container full! \n";
               break;
           }
          
           break;

       case 3:
           cout << "Enter the amount to remove: ";
           cin >> amount;
           piggy.removeCoins(amount);
           break;

       case 4:
           exit(0);
       }
       cout <<"Press any key to continue. \n";
   }
   while(true);//Loop again if user did not enter choice 4
}

//**********Output*****************

/*
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 1

        The piggy bank contains:
        0 cents
        0 nickels
        0 dimes
        0 quarters

        The piggy bank contains a total balance of $0.00
Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 2

You have decided to save money (good idea!). Please Enter
the number of coins to deposit as integers greater than or equal to zero

How many cents would you like to deposit? 5
How many nickels would you like to deposit? 5
How many dimes would you like to deposit? 5
Piggy Bank is full
Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 3
Enter the amount to remove: 10
Remove:
 5 cents, 1 nickels, 0 dimes, and 0 quarters.
 For a total of $0.10

Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 2

You have decided to save money (good idea!). Please Enter
the number of coins to deposit as integers greater than or equal to zero

How many cents would you like to deposit? 1
How many nickels would you like to deposit? 1
How many dimes would you like to deposit? 1
How many quarters would you like to deposit? 1
Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 3
Enter the amount to remove: 40
Remove:
 0 cents, 1 nickels, 1 dimes, and 1 quarters.
 For a total of $0.40

Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter: 1

        The piggy bank contains:
        1 cents
        4 nickels
        0 dimes
        0 quarters

        The piggy bank contains a total balance of $0.21
Press any key to continue.
****************** PIGGY BANK MAIN MENU ******************
        1.Show piggy bank contents and total balance.
        2.Deposit coins in the piggy bank
        3.Withdraw coins from the piggy bank
        4.Exit the program
************************************************************
What would you like to do? Select a number (1-4), then press Enter:
*/