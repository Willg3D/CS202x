#include <iostream>
#include <string> //std::stod
#include <stdlib.h> //std::strtod

double cpp_ftoc(const char* str) {
	std::string temp(str);
	temp.erase(0, 19);
	double f = std::stod(temp);
	return ((f - 32.0) * (5.0 / 9.0));
}

double cpp_ctof(const char* str) {
	double c = strtod(str, nullptr);
	return ((c * 1.8) + 32);
}

int main(int argc, char* str) {
	std::string test = "temperature --ftoc -40";
	char* c = const_cast<char*>(test.c_str());
	//cpp_ftoc(c);
	std::cout << cpp_ftoc(c);
	return 0;
}