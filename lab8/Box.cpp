#include <iostream>
#include "Box.h"

int Box::_amount = 0;

// SetValues of Box
void Box::setValues(int w, int l, int h)
{
	_width = w;
	_length = l;
	_hieght = h;
}

int Box::getVolume() const
{
	return _width * _length * _hieght;
}
// Default Constructor
Box::Box()
{
	_width = 0;
	_length = 0;
	_hieght = 0;

	_amount++; //static
	std::cout << "Default Constructor Called Amount: " << _amount << std::endl;
}
// Unique construcctor that allows value setting
Box::Box(int w, int l, int h)
{
	_width = w;
	_length = l;
	_hieght = h;
	std::cout << "Set Value Constructor Called" << std::endl;
	_amount++; //static

}

// Copies Box values to other Box
Box::Box(const Box& old)
{
	_width = old._width;
	_length = old._length;
	_hieght = old._hieght;
	std::cout << "Copy Constructor Called" << std::endl;
	_amount++; //static
}
// Destructor
Box::~Box()
{
	_amount--;
	std::cout << "Destructor Called Amount: " << _amount << std::endl;

}

std::ostream& operator << (std::ostream& out, const Box& c) {
	out << "Width: " << c._width << ", Length: " << c._length << ", Hieght: "
		<< c._hieght << std::endl << "Box Volume: " << c.getVolume() << std::endl;;
	return out;
}