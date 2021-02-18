#include "complex.h"

Complex::Complex(double r, double i): _real(r), _imaginary(i){
}

Complex& Complex::operator+=(const Complex& rhs)
{
	_real = _real + rhs._real;
	_imaginary = _imaginary + rhs._imaginary;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs){
	return os << rhs._real << "+" << rhs._imaginary << "i";
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	auto temp{ lhs };
	temp += rhs;
	return temp;
}
