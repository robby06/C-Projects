#include<cstdint>

#include <iostream>

#include<cstdlib>

#include "Log.h"

using namespace std;

template <typename T>

void CValueCal(T&); // enter a number from keyboard

void displayItems(const Log<double>&);

void addItems(Log<double>&);

void searchItem(const Log<double>&);

void removeItem(Log<double>&);

void removeCopies(Log<double>&);

int main()

{

    Log<double> l1;

    int menuChoice = 0;

    bool quit = false;

    while (!quit)

    {

        system("cls"); // clears the console screen

        std::cout<< "1. Show List contents\n";

        std::cout<< "2. Add item(s) to the List\n";

        std::cout << "3. Search for an item in the List\n";

        std::cout << "4. Withdraw single item from the List\n";

        std::cout << "5. Withdraw all copies of an item from the List\n";

        std::cout << "6. Exit the program\n\n";

        std::cout << "What would you like to do? Select a number (1 - 6), then press Enter: ";

        CValueCal(menuChoice);

        switch (menuChoice)

        {

        case 1:

            displayItems(l1);

            system("pause"); // causes program to pause until user hits a key

            break;

        case 2:

            std::cout << "You chose to add value(s) to the List.\n";

            std::cout << "Type the double(s) that will be stored,\n";

            addItems(l1);

            system("pause"); // causes program to pause until user hits a key

            break;

        case 3:

            std::cout << "You chose to search for a value in the List.\n";

            std::cout << "Type the double to be searched:\n";

            searchItem(l1);

system("pause"); // causes program to pause until user hits a key

            break;

        case 4:

            std::cout << "You chose to remove a value from theList,\n";

            std::cout << "Type the double to be removed:\n";

            removeItem(l1);

            system("pause"); // causes program to pause until user hits a key

            break;

        case 5:

            std::cout << "You chose to remove all copies of a value from the List,\n";

            std::cout << "Type the double to be completely removed:\n";

            removeCopies(l1);

            system("pause"); // causes program to pause until user hits a key

            break;

        case 6:

            quit = true;

            std::cout <<"exit";

            break;

        default:

            std::cout << "Invalid menu choice. Please try again.\n\n";

            system("pause"); // causes program to pause until user hits a key

        }

    }

    std::cout << "Closing...\n";

    return 0;

}

template<typename T>

void CValueCal(T& var) // enter a number from keyboard

{

    std::cin >> var;

    while (std::cin.fail() || std::cin.get() != '\n') // if error encountered

    {

        std::cout << "Invalid entry! Please re-enter value: ";

        std::cin.clear(); // clears any error flag

        std::cin.ignore(80, '\n'); // clears input buffer

        std::cin >> var;

    }

    std::cin.clear();

}

void displayItems(const Log<double>& doubles)

{

    if (doubles.size() == 0)

        std::cout << "Log empty!\n";

    else if (doubles.size() > 100)

    {

        std::cout << "Log too long to be displayed!\n";

        std::cout << "Log size: " << doubles.size() ;

    }

    else

    {

        std::cout << "Here are the contents:\n";

        for (Log<double>::const_iterator iLoc = doubles.begin(); iLoc != doubles.end(); iLoc++)

           std:: cout << (double)*iLoc << ", ";

        std::cout << "\b\b \n"; // delete last space and comma

        std::cout << "Log size: " << doubles.size() ;

    }

}

void addItems(Log<double>& doubles)

{

    std::cout << "Press \"q\" when you are done:\n";

    double itemInput;

    while (true) // while valid double is entered

    {

        std::cin >> itemInput;

        if (std::cin.fail() == false)

            doubles.push_back(itemInput);

        else

        {

            std::cin.clear(); // clear and ignore bad input

            std::cin.ignore(80, '\n');

            break; // invalid input

        }

    }

}

void searchItem(Log<double>& doubles)

{

    if (doubles.size() == 0)

        std::cout << "Log empty!\n";

    else

    {

        double itemInput;

        CValueCal(itemInput);

        size_t index = 0;

        Log<double>::iterator iLoc =doubles.begin();

        while (iLoc!= doubles.end())

        {

            if (*iLoc == itemInput)

            {

                std::cout << "Value " << itemInput << " found at node # " << index ;

                break;

            }

            index++;

            iLoc++;

        }

        if (iLoc == doubles.end())

            std::cout << "Value " << itemInput << " not found!\n";

    }

}

void removeItem(Log<double>& doubles)

{

    if (doubles.size() == 0)

        std::cout << "Log empty!\n";

    else

    {

        double itemInput;

        CValueCal(itemInput);

        size_t index = 0;

        Log<double>::iterator iLoc = doubles.begin();

        while (iLoc != doubles.end())

        {

            if (*iLoc == itemInput)

            {

                std::cout << "Value " << itemInput << " removed from node # " << index ;

                doubles.erase(iLoc);

                break;

            }

            index++;

            iLoc++;

        }

        if (iLoc == doubles.end())

            std::cout << "Value not found!\n";

    }

}

void removeCopies(Log<double>& doubles)

{

    if (doubles.size() == 0)

        std::cout << "Log empty!\n";

    else

    {

        double itemInput;

        CValueCal(itemInput);

        size_t index = 0;

        size_t nbrDeleted = 0;

        Log<double>::iterator iLoc = doubles.begin();

        while (iLoc != doubles.end())

        {

            if (*iLoc == itemInput)

            {

                std::cout << "Value " << *iLoc << " removed from node # " << index ;

                iLoc = doubles.erase(iLoc);

                nbrDeleted++;

            }

            else

                iLoc++;

            index++;

        }

        if (nbrDeleted == 0)

            std::cout << "Value not found!\n";

    }

}