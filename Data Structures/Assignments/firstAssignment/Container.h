#ifndef CONTAINER_H
#define CONTAINER_H

enum coin { cent = 1, nickel = 5, dime = 10, quarter = 25 };		//declare the enumerated type

// Main class 
class Container
{
    private:
        int    number;
        int    type;
        double value;
      
    public:
		Container();				//default constructor
        Container(int, int);
        int    getNumber();
        int    getType();
        double getValue();
        void   print();
};

//Cents class of Container class
class Cents: public Container
{
    public:
        Cents (int number = 0);
		static const double VALUE;
};

//Nickel class of Container class
class Nickels : public Container
{
    public:
        Nickels (int number = 0);
        static const double VALUE;
};

//Dimes class of Container class
class Dimes : public Container
{
    public:
        Dimes (int number = 0);
		static const double VALUE;
};

//Quarter class of Container class
class Quarters : public Container
{
    public:
        Quarters (int number = 0);
        static const double VALUE;
     
};
#endif