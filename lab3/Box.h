#ifndef Box_H
#define Box_H
#include<iostream>
#include<string>

class Box
{
public:
	void setValues(int, int, int);
	int getVolume() const;
	Box();
	Box(int, int, int); // constructor to set values
	Box(const Box&);
	~Box();
private:
	int _width, _length, _hieght;
};

#endif