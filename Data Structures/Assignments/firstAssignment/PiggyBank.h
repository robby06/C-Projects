#ifndef PIGGYBANK_H
#define PIGGYBANK_H
//import Container header file
#include "Container.h"

using namespace std;

//Piggy Bank class
class PiggyBank
{
    public:
		//Default constructor
        PiggyBank();
        void addCoins (Container& c);
        void removeCoins (int amount);
        double getValue();
        int getCount();
		void print();

    private:
        int numCents;
        int numNickels;
        int numDimes;
		int numQuarters;
        double value;
};
#endif