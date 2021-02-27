// William Glass
// HW3
// CS202x
#include "Money.hpp"
#include<iostream>
using std::cout;


Money& Money::operator+=(const Money& lS)
{
	_cents = _cents + lS._cents;
	return *this;
}

Money& Money::operator-=(const Money& lS)
{
	*this = *this - lS;
	return *this;
}

//Money& Money::operator*=(const Money& lS)
//{
//	_cents *= lS._cents;
//	return *this;
//}

Money& Money::operator*=(const double& lS)
{
	_cents *= lS;
	return *this;
}

Money& Money::operator*=(const int& lS)
{
	_cents *= lS;
	return *this;
}

//Money& Money::operator/=(const Money& lS)
//{
//	_cents /= lS._cents;
//	return *this;
//}

Money& Money::operator/=(const double& lS)
{
	_cents /= lS;
	return *this;
}

Money& Money::operator=(const Money& lS)
{
	_cents = lS._cents;
	return *this;

}

Money::Money() : _cents(0)
{

}

Money::Money(int cents): _cents(cents)
{

}

Money::Money(int dollars, int cents)
{
	dollars *= 100;
	_cents = dollars + cents;
}

Money::Money(double cash)
{
	cash *= 100; // converts for rounding
	if ((cash - floor(cash)) >= 0.5){cash = ceil(cash);}
	else{cash = floor(cash);}
	_cents =  (int)cash;
}

Money::Money(const Money& old) : _cents(old._cents)
{
}

Money::~Money()
{
}

std::ostream& operator<<(std::ostream& os, const Money& cash)
{	//inefficient way to print values, oh well.
	int cent_value = (cash._cents % 100); // finds cent values
	if (cent_value < 0) { cent_value *= -1; } // converts - value to +
	if (cash._cents >= 0){ // for + values
		os << "$" << (cash._cents - cent_value) / 100 << ".";
	}
	if (cash._cents < 0) {	// for - values (so - is in front of $)
		os << "-$" << ((cash._cents - cent_value) / 100)*-1 << ".";
	}
	if (cent_value != 0) {
		if (cent_value < 10) {// in case cent value is less than 10
			return os << "0" << cent_value;	// returns value so that there are 2 digits after .
		}
		return os << cent_value;// returns cent value if >10
	}
	return os << "00";	// in case cent value is zero
}

bool operator==(const Money& lS, const Money& rS)
{
	return lS._cents == rS._cents;
}

bool operator<(const Money& lS, const Money& rS)
{
	return lS._cents < rS._cents;
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

Money operator*(const double& lS, const Money& rS)
{
	Money temp{ (int)lS * rS._cents };
	return temp;
}

Money operator*(const Money& lS, const double& rS)
{
	Money temp{ lS._cents * (int)rS };
	return temp;
}

Money operator/(const double& lS, const Money& rS)
{
	Money temp{ (int)lS / rS._cents };
	return temp;
}

Money operator/(const Money& lS, const double& rS)
{
	Money temp{ lS._cents / (int)rS };
	return temp;
}


bool operator!=(const Money& lS, const Money& rS)
{
	return !(lS == rS);
}

bool operator>(const Money& lS, const Money& rS)
{
	return rS < lS;
}

bool operator<=(const Money& lS, const Money& rS)
{
	return !(lS > rS);
}

bool operator>=(const Money& lS, const Money& rS)
{
	return !(lS < rS);
}

Money operator-(const Money& lS, const Money& rS)
{
	return rS + -lS;
}




