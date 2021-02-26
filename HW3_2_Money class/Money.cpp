#include "Money.hpp"
#include<iostream>


Money::Money()// : _cents(0)
{
	_cents = 0;
}

Money::Money(double cash)
{
	_cents = (int)(cash * 100);
}

Money::Money(const Money& old) : _cents(old._cents)
{
}

Money::~Money()
{
}

std::ostream& operator<<(std::ostream& os, const Money& money)
{
	double dolars = (double)money._cents;
	dolars /= 100;
	return os << "$" << dolars;
}
