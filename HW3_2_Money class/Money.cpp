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

std::ostream& operator<<(std::ostream& os, const Money& cash)
{
	int cent_value = (cash._cents % 100);
	if (cent_value < 0) { cent_value *= -1; }
	os << "$" << (cash._cents - cent_value)/100 << ".";
	if (cent_value != 0) { return os << cent_value; }
	return os << "00";
}
