#include <iostream>

void printPointer(int i) {
	int* iptr = &i;
	// the unary * operator dereferences the pointer
	std::cout << "i = " << *iptr << "\n";
	std::cout << " & i = " << iptr << "\n";
}

int main() {


	return 0;
}