#include <iostream>
#include <string> //std::stod
#include <stdlib.h> //std::strtod

double cpp_ftoc(const char* str) {
	std::string temp(str);
	temp.erase(0, 19); // removes extra everything but num
	double f = std::stod(temp);
	return ((f - 32.0) * (5.0 / 9.0));
}

double cpp_ctof(const char* str) {
	double c = strtod(str, nullptr);
	return ((c * 1.8) + 32.0);
}

int main(int argc, char* str) {
	std::string cInput = "temperature --ftoc 32";
	char* c = const_cast<char*>(cInput.c_str());
	std::cout << "32f to c: "<<cpp_ftoc(c) << std::endl;
	std::string fInput = "temperature --ctof 0";
	char* f = const_cast<char*>(fInput.c_str());
	std::cout << "0c to f: " << cpp_ctof(f) << std::endl;
	return 0;
}