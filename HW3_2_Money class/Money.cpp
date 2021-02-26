#include "Money.hpp"
#include<iostream>


Money::Money()// : _cents(0)
{
	_cents = 0;
}

Money::Money(double cash)
{

	cash *= 100;
	if ((cash - floor(cash)) >= 0.5){cash = ceil(cash);}
	else{cash = floor(cash);}
	_cents =  cash;
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
	if (cash._cents >= 0){
		os << "$" << (cash._cents - cent_value) / 100 << ".";
	}
	if (cash._cents < 0) {
		os << "-$" << ((cash._cents - cent_value) / 100)*-1 << ".";
	}
	if (cent_value != 0) {
		if (cent_value < 10) {
			return os << "0" << cent_value;
		}
		return os << cent_value;
	}
	return os << "00";
}

bool operator==(const Money& rS, const Money& lS)
{
	return rS._cents == lS._cents;
}

bool operator<(const Money& rS, const Money& lS)
{
	return rS._cents < lS._cents;
}

bool operator!=(const Money& rS, const Money& lS)
{
	return !(rS == lS);
}

bool operator>(const Money& rS, const Money& lS)
{
	return lS < rS;
}

bool operator<=(const Money& rS, const Money& lS)
{
	return !(rS > lS);
}

bool operator>=(const Money& rS, const Money& lS)
{
	return !(rS < lS);
}



