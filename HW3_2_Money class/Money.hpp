#ifndef Money_HPP
#define Money_HPP
#include<iostream>


class Money
{
public:
	Money(); // Default Constructor
	Money(int); // constructor to set values
	Money(const Money&); // Copy constructor
	~Money(); // Destructor
private:
	int _cents;
};
#endif