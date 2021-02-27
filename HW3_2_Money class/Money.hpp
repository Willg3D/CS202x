// William Glass
// HW3
// CS202x
#ifndef Money_HPP
#define Money_HPP
#include<iostream>


class Money
{
	friend std::ostream& operator<<(std::ostream&, const Money& cents);
	friend bool operator==(const Money& lS, const Money& rS);
	friend bool operator<(const Money& lS, const Money& rS);
	friend Money operator+(const Money& lS, const Money& rS);
	friend Money operator-(const Money& lS);
	friend Money operator*(const double &lS, const Money& rS);
	friend Money operator*(const Money& lS, const double& rS);
	friend Money operator/(const double& lS, const Money& rS);
	friend Money operator/(const Money& lS, const double& rS);



public:
	Money& operator+=(const Money& lS);
	Money& operator-=(const Money& lS);
	//Money& operator*=(const Money& lS); // not required
	Money& operator*=(const double& lS);
	Money& operator*=(const int& lS);
	//Money& operator/=(const Money& lS); // not required
	Money& operator/=(const double& lS);
	Money& operator=(const Money& lS);


	Money(); // Default Constructor
	Money(int);// for cents
	Money(int, int); // for dollars and cents
	Money(double); // constructor to set values in dollars
	Money(const Money&); // Copy constructor
	~Money(); // Destructor
private:
	int _cents;
};

bool operator!=(const Money& lS, const Money& rS);
bool operator>(const Money& lS, const Money& rS);
bool operator<=(const Money& lS, const Money& rS);
bool operator>=(const Money& lS, const Money& rS);

Money operator-(const Money& lS, const Money& rS);


#endif