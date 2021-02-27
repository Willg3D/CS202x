// William Glass
// HW3
// CS202x
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
#include <istream>
#include <vector>
using std::vector;
#include "StopWatch.h"


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

// struct for tokens
struct TokenAndPosition{
	string _token;
	int _line;
	unsigned int _column;
};

// finds tokens in lines
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

// read files to find tokens, lines, and columns
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
			column = 0;

		}
	}
	return tokens;
}

// Prints Tokens
void printTokens(const string lineonly, const vector<TokenAndPosition>& tokens) {

	for (size_t i = 0; i < tokens.size(); i++){
		if (lineonly != "--lineonly"){
			cout << "Line  " << tokens[i]._line <<
				", Column " << tokens[i]._column << ": \"" <<
				tokens[i]._token << "\"" << std::endl;
		}
		else{
			cout << "Line  " << tokens[i]._line << ": \"" <<
				tokens[i]._token << "\"" << std::endl;
		}
		
	}
}


int main(int argc, char* argv[]) {
	// Big Note: For some reason in Visual Studios argc by default is 1 and
	// first element in argv is nonsense. Command arguments start at argv[1]
	string startWord = argv[1]; // "tokenizer"
	Stopwatch readtime; // time for reading
	std::vector<TokenAndPosition> tokens_vector = readFile_tokenizer(argv[2]);
	readtime.stop();
	Stopwatch printtime; // time for printing
	// determine if line only should print
	if (startWord == "tokenizer" && argc == 4) {
		printTokens(argv[3], tokens_vector);
	}
	else if(startWord == "tokenizer" && argc == 3){
		printTokens("", tokens_vector);
	}
	if (startWord != "tokenizer") { return 1; }
	printtime.stop();
	cout << "Read Time msec: " << readtime.time_msec() << std::endl;
	cout << "Print Time msec: " << printtime.time_msec() << std::endl;


	return 0;
}