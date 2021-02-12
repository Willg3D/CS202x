#include <iostream>
using std::cout;
using std::endl;

int staticData;
auto staticData_ptr = &staticData;

// Changed print pointer fuction
void printPointer(int *i) {
	//int* iptr = &i;
	// the unary * operator dereferences the pointer
	std::cout << "i = " << *i << "\n";
	std::cout << " & i = " << i << "\n";
}

int main() {
	int stackData;
	auto stackData_ptr = &stackData;
	auto freeStore_ptr = new int;

	cout << "Static Data Pointer:" << endl;
	printPointer(staticData_ptr);
	cout << "Stack Data Pointer:" << endl;
	printPointer(stackData_ptr);
	cout << "Free Store Pointer:" << endl;
	printPointer(freeStore_ptr);

	// Quick Test
	if (stackData_ptr < staticData_ptr){
		cout << "\nStack data pointer has a lower address than static data pointer" << endl;
	}
	if (stackData_ptr > staticData_ptr) {
		cout << "\nStatic data pointer has a lower address than stack data pointer" << endl;
	}
	if (stackData_ptr < freeStore_ptr) {
		cout << "\nStack data pointer has a lower address than free store pointer" << endl;
	}
	if (stackData_ptr > freeStore_ptr) {
		cout << "\nFree store data pointer has a lower address than stack store pointer" << endl;
	}
	if (staticData_ptr < freeStore_ptr) {
		cout << "\nStatic data pointer has a lower address than free store pointer" << endl;
	}
	if (staticData_ptr > freeStore_ptr) {
		cout << "\nFree store pointer has a lower address than static data pointer" << endl;
	}

	// Hard coded answer based on test
	cout << "\nOrder of Addresses from High to Low is Free Store, Stack Data, Static Data" << endl;


}