#include <iostream>
#include "Box.h"
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::make_shared;
using std::shared_ptr;

int main() {
	cout << "\n1. Making Raw ptr:" << endl;
	Box* rptr = new Box;

	cout << "\n2. Creating unique_ptr" << endl;
	auto uptr = make_unique<Box>(2,2,2);

	cout << "\n3. Transfer Ownership of unique_ptr" << endl;
	std::unique_ptr<Box> uptr_c = move(uptr);

	cout << "\n4. Calling a member function" << endl;
	//uptr_c->setValues(2, 2, 2);
	cout << "Volume: " << uptr_c->getVolume() << endl;

	cout << "\n5. Shared ptr dynamically aloc" << endl;
	auto sptr = make_shared<Box>(3, 3, 3);

	cout << "\n6. Make another shared ptr" << endl;
	shared_ptr<Box> sptr2 = sptr;
	cout << "Volume: " << sptr2->getVolume() << endl;



}