#ifndef Money_HPP
#define Money_HPP
#include<iostream>


class Money
{
	friend std::ostream& operator<<(std::ostream&, const Money& cents);
	friend bool operator==(const Money& rS, const Money& lS);
	friend bool operator<(const Money& rS, const Money& lS);
	friend Money operator+(const Money& rS, const Money& lS);
	friend Money operator-(const Money& lS);


public:
	Money& operator+=(const Money& rS);


	Money(); // Default Constructor
	Money(double); // constructor to set values
	Money(const Money&); // Copy constructor
	~Money(); // Destructor
private:
	int _cents;
};

bool operator!=(const Money& rS, const Money& lS);
bool operator>(const Money& rS, const Money& lS);
bool operator<=(const Money& rS, const Money& lS);
bool operator>=(const Money& rS, const Money& lS);

Money operator-(const Money& rS, const Money& lS);

#endif