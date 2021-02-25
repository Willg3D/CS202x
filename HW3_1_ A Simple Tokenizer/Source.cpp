#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
#include <sstream> //istreamstring used for words
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

void readFile_vector(string filename, std::vector<string>& book) {
	std::ifstream open(filename);
	string word;
	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string data;
			std::getline(open, data);
			std::istringstream iss(data);

			while (iss >> word) {
				book.push_back(word);
			}
		}
	}
}

int main() {
	//std::string tokens;
	//std::getline(std::cin, tokens);
	//std::vector<std::string> tokens_vector = stringW_to_Vector(tokens);



	return 0;
}