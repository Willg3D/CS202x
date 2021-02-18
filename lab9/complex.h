#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
	friend std::ostream& operator<<(std::ostream&, const Complex& rhs);
	friend Complex operator+(const Complex& lhs, const Complex& rhs);
public:
	Complex(double = 0, double = 0);
	Complex& operator+=(const Complex& rhs);
private:
	double _real;
	double _imaginary;
};


#endif