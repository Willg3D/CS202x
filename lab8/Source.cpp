#include <iostream>
using std::cout;
using std::endl;
#include "Box.h"

//int exampleF() {
//	static int variable = 0;
//	variable++;
//	return variable;
//}

int main() {
	/*cout << exampleF() << endl;
	cout << exampleF() << endl;*/

	//cout << "Num of Boxes: " << Box::getAmount() << endl;;
	//Box test1;
	Box test2(2,2,2);
	cout << test2;
	
}