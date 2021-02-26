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
	Money& operator-=(const Money& rS);
	Money& operator*=(const Money& rS); // not required
	Money& operator*=(const double& rS);
	Money& operator/=(const Money& rS); // not required
	Money& operator/=(const double& rS);

	Money(); // Default Constructor
	Money(int);
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