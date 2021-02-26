#include "Money.hpp"
#include<iostream>
using std::cout;


Money& Money::operator+=(const Money& rS)
{
	_cents = _cents + rS._cents;
	return *this;
}

Money& Money::operator-=(const Money& rS)
{
	*this = *this - rS;
	return *this;
}

Money& Money::operator*=(const Money& rS)
{
	_cents *= rS._cents;
	return *this;
}

Money& Money::operator*=(const double& rS)
{
	_cents *= rS;
	return *this;
}

Money& Money::operator/=(const Money& rS)
{
	_cents /= rS._cents;
	return *this;
}

Money& Money::operator/=(const double& rS)
{
	_cents /= rS;
	return *this;
}

Money::Money()// : _cents(0)
{
	_cents = 0;
}

Money::Money(int cash)
{
	_cents = cash;
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

Money operator+(const Money& rS, const Money& lS)
{
	Money temp{lS};
	temp += rS;
	return temp;
}

Money operator-(const Money& lS)
{
	return -lS._cents;
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

Money operator-(const Money& rS, const Money& lS)
{
	return { lS + -rS };
}



