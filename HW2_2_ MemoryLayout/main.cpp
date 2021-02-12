#include <iostream>

int staticData = 2;
auto staticData_ptr = &staticData;

// Changed print pointer fuction
void printPointer(int *i) {
	//int* iptr = &i;
	// the unary * operator dereferences the pointer
	std::cout << "i = " << *i << "\n";
	std::cout << " & i = " << i << "\n";
}

int main() {
	int stackData = 0;
	auto stackData_ptr = &stackData;
	auto freeStore_ptr = new int;



	return 0;
}