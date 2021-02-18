#include <iostream>
using std::cout;
using std::endl;
#include "complex.h"

int main() {
	Complex v1(1,2);
	Complex v2(2,3);
	Complex v3;
	v3 = v1 + v2;
	cout << v3 << endl;
	cout << 1+v2 << endl;

}