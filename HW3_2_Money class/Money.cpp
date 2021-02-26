#include "Money.hpp"

Money::Money() : _cents(0)
{
}

Money::Money(int cents) :_cents(cents)
{
}

Money::Money(const Money& old) : _cents(old._cents)
{
}
