#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> stringW_to_Vector(const std::string &stringW) {
	std::string temp;
	std::vector<std::string> vector;
	int i = 0;
	for (size_t x = 0; x <= stringW.size(); x++) {
		if (stringW[x] != ' ') {
			temp.push_back(stringW[x]);
		}
		if (stringW[x] == ' ' || x == stringW.size()) {
			vector.push_back(temp);
			temp.clear();
			i++;
		}
	}
	return vector;
}

int main() {
	std::string tokens;
	std::getline(std::cin, tokens);
	std::vector<std::string> tokens_vector = stringW_to_Vector(tokens);


	//int numTokens = std::strlen(tokens.c_str());



	for (size_t i = 0; i < tokens_vector.size(); i++)
	{
		std::cout << tokens_vector[i] << "\n";
	}
	//	//std::string temp = 


	return 0;
}