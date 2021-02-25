#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
#include <sstream> //istreamstring used for words
#include <vector>

//std::vector<std::string> stringW_to_Vector(const std::string &stringW) {
//	std::string temp;
//	std::vector<std::string> vector;
//	int i = 0;
//	for (size_t x = 0; x <= stringW.size(); x++) {
//		if (stringW[x] != ' ') {
//			temp.push_back(stringW[x]);
//		}
//		if (stringW[x] == ' ' || x == stringW.size()) {
//			vector.push_back(temp);
//			temp.clear();
//			i++;
//		}
//	}
//	return vector;
//}

struct TokenAndPosition{
	string _token;
	int _line;
	unsigned int _column;
};

std::vector<TokenAndPosition> readFile_vector(string filename) {
	//TokenAndPosition token;
	std::vector<TokenAndPosition> tokens;
	std::ifstream open(filename);
	string word;
	int line = 0;

	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string data;
			std::getline(open, data);
			std::istringstream iss(data);
			line++;

			while (iss >> word) {
				tokens.push_back(TokenAndPosition{ word, line, 1 });
			}
		}
	}

	return tokens;
}

int main() {
	//std::string tokens;
	//std::getline(std::cin, tokens);
	std::vector<TokenAndPosition> tokens_vector = readFile_vector("test.txt");

	for (size_t i = 0; i < tokens_vector.size(); i++)
	{
		cout << tokens_vector[i]._token << " " << tokens_vector[i]._line <<
			" " << tokens_vector[i]._column << "\n";
	}



	return 0;
}