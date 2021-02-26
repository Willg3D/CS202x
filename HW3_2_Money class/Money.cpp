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

Money& Money::operator*=(const Money& lS)
{
	_cents *= lS._cents;
	return *this;
}

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

Money& Money::operator/=(const Money& lS)
{
	_cents /= lS._cents;
	return *this;
}

Money& Money::operator/=(const double& lS)
{
	_cents /= lS;
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
//
//Money operator*(Money& lS, const int& rS)
//{
//	
//	return { lS *= rS };
//}
//
//Money operator*(const int& lS, Money& rS)
//{
//	int temp = lS * rS._ce
//	return { rS *= lS };
//}



