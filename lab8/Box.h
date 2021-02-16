#ifndef Box_H
#define Box_H
#include<iostream>
//#include<ostream>
#include<string>



class Box
{
public:
	void setValues(int, int, int);
	int getVolume() const;
	Box(); // Default Constructor
	Box(int, int, int); // constructor to set values
	Box(const Box&); // Copy constructor
	~Box();

	//operator
	friend std::ostream& operator << (std::ostream& out, const Box& c);
	// Static
	static int getAmount() { return _amount; }
	static void setAmount(int newA) { _amount = newA;}

private:
	int _width, _length, _hieght;
	//Static Variable
	static int _amount;
};




#endif