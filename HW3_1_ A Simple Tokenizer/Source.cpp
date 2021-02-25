#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string tokens;
	std::vector<std::string> tokens_vector;
	std::getline(std::cin, tokens);

	int numTokens = std::strlen(tokens.c_str());
	std::string temp;
	int i = 0;
	for (size_t x = 0; x <= tokens.size(); x++){
		if (tokens[x] != ' '){
			temp.push_back(tokens[x]);
		}
		if (tokens[x] == ' ' || x == tokens.size()){
			tokens_vector.push_back(temp);
			temp.clear();
			i++;
		}
	}


	for (size_t i = 0; i < tokens_vector.size(); i++)
	{
		std::cout << tokens_vector[i] << "\n";
	}
	//	//std::string temp = 


	return 0;
}