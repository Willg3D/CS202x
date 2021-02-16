#include <iostream>
#include "Box.h"

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
	std::cout << "Default Constructor Called" << std::endl;
}
// Unique construcctor that allows value setting
Box::Box(int w, int l, int h)
{
	_width = w;
	_length = l;
	_hieght = h;
	std::cout << "Set Value Constructor Called" << std::endl;

}

// Copies Box values to other Box
Box::Box(const Box& old)
{
	_width = old._width;
	_length = old._length;
	_hieght = old._hieght;
	std::cout << "Copy Constructor Called" << std::endl;
}
// Destructor
Box::~Box()
{
	std::cout << "Destructor Called" << std::endl;
}

std::ostream& operator << (std::ostream& out, const Box& c) {
	out << "Box Volume: " << c.getVolume();
	return out;
}