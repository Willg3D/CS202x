#ifndef Money_HPP
#define Money_HPP
#include<iostream>


class Money
{
	friend std::ostream& operator<<(std::ostream&, const Money& cents);
public:
	Money(); // Default Constructor
	Money(double); // constructor to set values
	Money(const Money&); // Copy constructor
	~Money(); // Destructor
private:
	int _cents;
};
#endif