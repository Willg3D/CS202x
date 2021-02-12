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



	return 0;
}