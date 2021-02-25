#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
using std::vector;

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

vector<string> lineToTokens(const string& line) {
	std::string temp;
	std::vector<std::string> vector;
	int i = 0;
	for (size_t x = 0; x <= line.size(); x++) {
		if (line[x] != ' ') {
			temp.push_back(line[x]);
		}
		if (line[x] == ' ' || x == line.size()) {
			vector.push_back(temp);
			temp.clear();
			i++;
		}
	}
	return vector;
}

std::vector<TokenAndPosition> readFile_tokenizer(string filename) {
	//TokenAndPosition token;
	std::vector<string> temp;
	std::vector<TokenAndPosition> tokens;
	std::ifstream open(filename);
	int line = 0;
	unsigned int column = 0;

	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string data;
			std::getline(open, data);
			line++;
			temp = lineToTokens(data);
			for (size_t i = 0; i < temp.size(); i++){
				tokens.push_back(TokenAndPosition{ temp[i], line, column });
				column = column + temp[i].size() + 2;

			}

		}
	}

	return tokens;
}




int main() {

	std::vector<TokenAndPosition> tokens_vector = readFile_tokenizer("test.txt");

	for (size_t i = 0; i < tokens_vector.size(); i++)
	{
		cout << tokens_vector[i]._token << " " << tokens_vector[i]._line <<
			" " << tokens_vector[i]._column << "\n";
	}



	return 0;
}